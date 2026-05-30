class Solution {
public:
    int sumOfPrimesInRange(int n) {
        // 1. Find the reverse of n
        int temp = n;
        int r = 0;
        while (temp > 0) {
            r = r * 10 + (temp % 10);
            temp /= 10;
        }
        
        // 2. Define the bounds
        int start = std::min(n, r);
        int end = std::max(n, r);
        
        // 3. Sieve of Eratosthenes up to 'end'
        if (end < 2) return 0; // No primes exist below 2
        
        std::vector<bool> isPrime(end + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int p = 2; p * p <= end; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= end; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        
        // 4. Sum up all prime numbers in the inclusive range
        int primeSum = 0;
        for (int i = start; i <= end; i++) {
            if (isPrime[i]) {
                primeSum += i;
            }
        }
        
        return primeSum;
    }
};