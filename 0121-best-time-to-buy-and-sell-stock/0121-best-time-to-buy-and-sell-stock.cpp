class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Track the minimum price seen so far
        int maxProfit = 0;       // Track the maximum profit
        
        for (int price : prices) {
            // Update the minimum price
            if (price < minPrice) {
                minPrice = price;
            }
            
            // Calculate potential profit and update maxProfit if larger
            int profit = price - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        
        return maxProfit;
    }
};