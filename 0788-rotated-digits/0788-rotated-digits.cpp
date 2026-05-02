class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for (int num = 1; num <= n; num++) {
            int temp = num;
            bool isValid = true;
            bool isGood = false;

            while (temp > 0) {
                int digit = temp % 10;
                temp /= 10;

                // invalid digits
                if (digit == 3 || digit == 4 || digit == 7) {
                    isValid = false;
                    break;
                }

                // digits that change after rotation
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    isGood = true;
                }
            }

            if (isValid && isGood) {
                count++;
            }
        }

        return count;
    }
};