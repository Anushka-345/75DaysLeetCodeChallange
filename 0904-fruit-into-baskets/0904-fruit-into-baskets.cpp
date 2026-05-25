class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        unordered_map<int, int> mp; // Baskets tracking {fruit_type: count}
        int maxFruits = 0;
        
        for (int j = 0; j < fruits.size(); j++) {
            // Add the current fruit to our basket
            mp[fruits[j]]++;
            
            // If we have more than 2 types of fruit, shrink the window from the left
            while (mp.size() > 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]); // Completely remove the fruit type from baskets
                }
                i++; // Move left pointer forward
            }
            
            // Update the maximum fruits we can collect in a valid stretch
            maxFruits = max(maxFruits, j - i + 1);
        }
        
        return maxFruits;
    }
};