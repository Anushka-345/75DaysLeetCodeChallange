class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, ' ');
        
        // Step 1: Greedily assign characters
        // If lcp[i][j] > 0, positions i and j must share the same character
        // Assign the smallest available character to each unassigned position
        char nextChar = 'a';
        for (int i = 0; i < n; i++) {
            if (word[i] != ' ') continue; // already assigned
            
            if (nextChar > 'z') return ""; // ran out of characters
            
            word[i] = nextChar;
            
            // All j where lcp[i][j] > 0 must have same character as i
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    if (word[j] == ' ') {
                        word[j] = nextChar;
                    }
                    // if word[j] already set to something else, 
                    // validation will catch it
                }
            }
            nextChar++;
        }
        
        // Step 2: Validate the constructed string
        // Check lcp values match what the string implies
        // Use bottom-up DP: compute expected lcp from the string
        
        // Validate diagonal: lcp[i][i] must be n - i
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }
        
        // Validate symmetry and recurrence relation
        // Process from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == j) continue;
                
                // Symmetry check
                if (lcp[i][j] != lcp[j][i]) return "";
                
                if (word[i] == word[j]) {
                    // Characters match => lcp[i][j] must be 1 + lcp[i+1][j+1]
                    int expected = 1;
                    if (i + 1 < n && j + 1 < n) {
                        expected = 1 + lcp[i + 1][j + 1];
                    }
                    if (lcp[i][j] != expected) return "";
                } else {
                    // Characters differ => lcp[i][j] must be 0
                    if (lcp[i][j] != 0) return "";
                }
            }
        }
        
        return word;
    }
};