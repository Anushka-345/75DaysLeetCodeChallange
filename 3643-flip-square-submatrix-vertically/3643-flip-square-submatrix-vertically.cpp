class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            int top_row = x + i;
            int bottom_row = x + k - 1 - i;
            
            // Swap elements in the relevant columns
            for (int j = 0; j < k; j++) {
                swap(grid[top_row][y + j], grid[bottom_row][y + j]);
            }
        }
        return grid;
    }
};