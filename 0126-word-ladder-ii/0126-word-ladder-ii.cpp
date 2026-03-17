class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (wordSet.find(endWord) == wordSet.end()) return res;

        unordered_map<string, vector<string>> parents; // child -> list of parents
        unordered_map<string, int> levels; // word -> level in BFS
        queue<string> q;

        q.push(beginWord);
        levels[beginWord] = 0;

        int level = 0;
        bool foundEnd = false;

        while (!q.empty() && !foundEnd) {
            level++;
            int sz = q.size();
            unordered_set<string> visitedThisLevel;

            for (int i = 0; i < sz; i++) {
                string word = q.front(); q.pop();

                string original = word;
                for (int j = 0; j < word.size(); j++) {
                    char oldChar = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == oldChar) continue;
                        word[j] = c;
                        if (wordSet.count(word)) {
                            if (!levels.count(word)) {
                                levels[word] = level;
                                q.push(word);
                                visitedThisLevel.insert(word);
                            }
                            if (levels[word] == level) {
                                parents[word].push_back(original);
                            }
                            if (word == endWord) foundEnd = true;
                        }
                    }
                    word[j] = oldChar;
                }
            }

            for (string w : visitedThisLevel)
                wordSet.erase(w); // avoid revisiting
        }

        if (!foundEnd) return res;

        // Backtracking from endWord to beginWord using parents map
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, res);
        return res;
    }

private:
    void dfs(string &word, string &beginWord, unordered_map<string, vector<string>> &parents,
             vector<string> &path, vector<vector<string>> &res) {
        if (word == beginWord) {
            vector<string> tmp = path;
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            return;
        }

        for (string &p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};
