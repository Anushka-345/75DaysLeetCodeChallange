class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, total = 0;
        int i = 0, j = 0;
        int mod = 1e9 + 7;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                sum1 += nums1[i++];
            } else if (nums2[j] < nums1[i]) {
                sum2 += nums2[j++];
            } else {
                total += max(sum1, sum2) + nums1[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        
        while (i < nums1.size()) sum1 += nums1[i++];
        while (j < nums2.size()) sum2 += nums2[j++];
        
        return (total + max(sum1, sum2)) % mod;
    }
};