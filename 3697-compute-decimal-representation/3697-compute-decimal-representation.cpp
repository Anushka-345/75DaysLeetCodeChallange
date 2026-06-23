class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> result;
        long long place_value = 1;
        
        // Extract components from right to left (ones place upwards)
        while (n > 0) {
            int digit = n % 10;
            if (digit > 0) {
                result.push_back(digit * place_value);
            }
            n /= 10;
            place_value *= 10;
        }
        
        // Reverse the array to get components in descending order
        reverse(result.begin(), result.end());
        
        return result;
    }
};