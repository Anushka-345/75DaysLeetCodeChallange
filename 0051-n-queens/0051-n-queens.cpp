class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queens(n, -1); // queens[i] = column position of queen in row i
        backtrack(result, queens, 0, n);
        return result;
    }

private:
    void backtrack(vector<vector<string>> &result, vector<int> &queens, int row, int n) {
        if (row == n) {
            result.push_back(generateBoard(queens, n));
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(queens, row, col)) {
                queens[row] = col;
                backtrack(result, queens, row + 1, n);
                queens[row] = -1; // backtrack
            }
        }
    }

    bool isSafe(vector<int> &queens, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row))
                return false;
        }
        return true;
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};
