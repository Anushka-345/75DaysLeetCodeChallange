class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        // convert to 4-digit strings
        string a = string(4 - to_string(num1).length(), '0') + to_string(num1);
        string b = string(4 - to_string(num2).length(), '0') + to_string(num2);
        string c = string(4 - to_string(num3).length(), '0') + to_string(num3);

        string result = "";

        // compare digit by digit
        for (int i = 0; i < 4; i++) {
            char mn = min({a[i], b[i], c[i]});
            result += mn;
        }

        // remove leading zeros
        return stoi(result);
    }
};