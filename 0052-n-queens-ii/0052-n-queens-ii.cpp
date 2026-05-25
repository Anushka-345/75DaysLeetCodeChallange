class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // Tracking sets for columns and diagonals
        unordered_set<int> cols;
        unordered_set<int> diagonals;     // row - col
        unordered_set<int> antiDiagonals; // row + col
        
        backtrack(0, n, cols, diagonals, antiDiagonals, count);
        return count;
    }

private:
    void backtrack(int row, int n, 
                   unordered_set<int>& cols, 
                   unordered_set<int>& diagonals, 
                   unordered_set<int>& antiDiagonals, 
                   int& count) {
        // Base case: If we've successfully placed queens in all rows
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int currDiag = row - col;
            int currAntiDiag = row + col;

            // If the column or either diagonal is under attack, skip this spot
            if (cols.count(col) || diagonals.count(currDiag) || antiDiagonals.count(currAntiDiag)) {
                continue;
            }

            // Place the queen (Choose)
            cols.insert(col);
            diagonals.insert(currDiag);
            antiDiagonals.insert(currAntiDiag);

            // Move to the next row (Explore)
            backtrack(row + 1, n, cols, diagonals, antiDiagonals, count);

            // Remove the queen (Un-choose / Backtrack)
            cols.erase(col);
            diagonals.erase(currDiag);
            antiDiagonals.erase(currAntiDiag);
        }
    }
};