class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: S1 is "0"
        if (n == 1) return '0';
        
        int length = (1 << n) - 1; // 2^n - 1
        int mid = length / 2 + 1;
        
        if (k == mid) {
            return '1';
        } else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            // Find the bit in the first half, then invert it
            // The mirrored position in the first half is: length - k + 1
            char correspondingBit = findKthBit(n - 1, length - k + 1);
            return (correspondingBit == '0') ? '1' : '0';
        }
    }
};