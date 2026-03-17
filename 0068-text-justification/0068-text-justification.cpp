class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = words[i].length();
            int j = i + 1;

            // Pack as many words as possible in the line
            while (j < n && lineLen + 1 + words[j].length() <= maxWidth) {
                lineLen += 1 + words[j].length();
                j++;
            }

            int numWords = j - i;
            string line;

            // Last line or line with one word
            if (j == n || numWords == 1) {
                line = words[i];
                for (int k = i + 1; k < j; k++)
                    line += " " + words[k];
                line += string(maxWidth - line.length(), ' '); // pad spaces at end
            } else {
                // Fully justify
                int totalSpaces = maxWidth;
                for (int k = i; k < j; k++)
                    totalSpaces -= words[k].length();

                int spaceBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    int spaces = spaceBetween + (extraSpaces-- > 0 ? 1 : 0);
                    line += string(spaces, ' ') + words[k];
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};