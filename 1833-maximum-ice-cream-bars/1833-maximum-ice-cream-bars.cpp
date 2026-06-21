#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        // Find the maximum cost to optimize the frequency array size
        int max_cost = 0;
        for (int cost : costs) {
            max_cost = std::max(max_cost, cost);
        }
        
        // Create a frequency array for counting sort
        std::vector<int> freq(max_cost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }
        
        int ice_cream_count = 0;
        
        // Iterate through all possible prices greedily
        for (int price = 1; price <= max_cost; ++price) {
            if (freq[price] == 0) continue;
            
            // If we can't even afford one bar at this price, we are done
            if (coins < price) break;
            
            // Calculate how many bars of this price we want vs how many we can afford
            long long total_cost_for_all = (long long)price * freq[price];
            
            if (coins >= total_cost_for_all) {
                // Buy all available bars at this price
                ice_cream_count += freq[price];
                coins -= total_cost_for_all;
            } else {
                // Buy as many as we can afford with the remaining coins
                int bars_to_buy = coins / price;
                ice_cream_count += bars_to_buy;
                break; // No coins left to buy more expensive bars
            }
        }
        
        return ice_cream_count;
    }
};