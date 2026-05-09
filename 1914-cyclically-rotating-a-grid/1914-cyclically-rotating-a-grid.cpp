class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> elements;

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // Top row
            for (int j = left; j <= right; j++)
                elements.push_back(grid[top][j]);

            // Right column
            for (int i = top + 1; i <= bottom - 1; i++)
                elements.push_back(grid[i][right]);

            // Bottom row
            for (int j = right; j >= left; j--)
                elements.push_back(grid[bottom][j]);

            // Left column
            for (int i = bottom - 1; i >= top + 1; i--)
                elements.push_back(grid[i][left]);

            int len = elements.size();

            // Counter-clockwise rotation
            int rot = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; i++) {
                rotated[i] = elements[(i + rot) % len];
            }

            int idx = 0;

            // Put back Top row
            for (int j = left; j <= right; j++)
                grid[top][j] = rotated[idx++];

            // Put back Right column
            for (int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = rotated[idx++];

            // Put back Bottom row
            for (int j = right; j >= left; j--)
                grid[bottom][j] = rotated[idx++];

            // Put back Left column
            for (int i = bottom - 1; i >= top + 1; i--)
                grid[i][left] = rotated[idx++];
        }

        return grid;
    }
};