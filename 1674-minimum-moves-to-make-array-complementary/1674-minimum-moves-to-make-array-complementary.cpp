class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        // diff array covers possible sums from 2 to 2 * limit
        // We use size 2 * limit + 2 to handle boundary increments safely
        vector<int> diff(2 * limit + 2, 0);
        int n = nums.size();

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            // 1. Default: 2 moves for all sums
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // 2. Range for 1 move: [min(a, b) + 1, max(a, b) + limit]
            // We subtract 1 from the 2-move default to make it 1 move
            int left = min(a, b) + 1;
            int right = max(a, b) + limit;
            diff[left] -= 1;
            diff[right + 1] += 1;

            // 3. Exactly 0 moves: sum == a + b
            // We subtract another 1 from the 1-move state to make it 0 moves
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int min_moves = n; // Max possible moves is n
        int current_moves = 0;
        
        // Sweep through the difference array to find the minimum
        for (int sum = 2; sum <= 2 * limit; ++sum) {
            current_moves += diff[sum];
            min_moves = min(min_moves, current_moves);
        }

        return min_moves;
    }
};