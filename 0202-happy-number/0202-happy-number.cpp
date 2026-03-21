class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getSum(n);

        while (fast != 1 && slow != fast) {
            slow = getSum(slow);                 // 1 step
            fast = getSum(getSum(fast));         // 2 steps
        }

        return fast == 1;
    }
};