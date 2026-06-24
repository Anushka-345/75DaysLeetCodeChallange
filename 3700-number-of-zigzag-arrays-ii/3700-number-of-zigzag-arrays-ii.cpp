#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;
    int m;

    // Helper matrix multiplication function
    vector<int> multiply(const vector<int>& A, const vector<int>& B) {
        vector<int> C(m * m, 0);
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < m; ++k) {
                if (A[i * m + k] == 0) continue;
                for (int j = 0; j < m; ++j) {
                    C[i * m + j] = (C[i * m + j] + 1LL * A[i * m + k] * B[k * m + j]) % MOD;
                }
            }
        }
        return C;
    }

    // Binary matrix exponentiation
    vector<int> matrixPower(vector<int> M, long long p) {
        vector<int> res(m * m, 0);
        for (int i = 0; i < m; ++i) res[i * m + i] = 1; // Identity matrix
        
        while (p > 0) {
            if (p & 1) res = multiply(res, M);
            M = multiply(M, M);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        m = r - l + 1;
        if (n == 1) return m;

        // Vectorized 1D arrays for m x m matrices to save cache overhead
        vector<int> U(m * m, 0), L(m * m, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) U[i * m + j] = 1; // U[i][j] = 1 if i < j
            for (int j = 0; j < i; ++j) L[i * m + j] = 1;     // L[i][j] = 1 if i > j
        }

        // We make (n - 1) total transitions
        long long steps = n - 1;
        long long pairs = steps / 2;

        // Combine two half-steps into a complete alternating block step
        vector<int> UL = multiply(U, L);
        vector<int> P = matrixPower(UL, pairs);

        // If the number of transitions is odd, multiply by one final trailing transition
        if (steps & 1) {
            P = multiply(L, P);
        }

        // Total up all paths
        long long total_sum = 0;
        for (int val : P) {
            total_sum = (total_sum + val) % MOD;
        }

        // Multiply by 2 to cover both patterns (starting with UP vs starting with DOWN)
        return (total_sum * 2) % MOD;
    }
};