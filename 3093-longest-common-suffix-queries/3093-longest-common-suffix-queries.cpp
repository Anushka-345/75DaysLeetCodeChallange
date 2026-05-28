#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int bestIndex;

    TrieNode(int index) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        bestIndex = index;
    }
};

class Solution {
private:
    TrieNode* root;

    void insert(const string& word, int wordIdx, const vector<string>& wordsContainer) {
        TrieNode* curr = root;
        
        // Update the root node's best index if this word is a better global default
        if (shouldUpdate(curr->bestIndex, wordIdx, wordsContainer)) {
            curr->bestIndex = wordIdx;
        }

        // Insert characters from right to left (suffix as prefix)
        for (int i = word.length() - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (!curr->children[c]) {
                curr->children[c] = new TrieNode(wordIdx);
            }
            curr = curr->children[c];

            // Update the node's cached best index based on the rules
            if (shouldUpdate(curr->bestIndex, wordIdx, wordsContainer)) {
                curr->bestIndex = wordIdx;
            }
        }
    }

    bool shouldUpdate(int currBestIdx, int newIdx, const vector<string>& wordsContainer) {
        if (wordsContainer[newIdx].length() < wordsContainer[currBestIdx].length()) {
            return true;
        }
        if (wordsContainer[newIdx].length() == wordsContainer[currBestIdx].length()) {
            return newIdx < currBestIdx; // Earliest occurrence tie-breaker
        }
        return false;
    }

    int search(const string& query) {
        TrieNode* curr = root;
        int lastBest = root->bestIndex;

        // Traverse from right to left
        for (int i = query.length() - 1; i >= 0; --i) {
            int c = query[i] - 'a';
            if (!curr->children[c]) {
                break;
            }
            curr = curr->children[c];
            lastBest = curr->bestIndex;
        }
        return lastBest;
    }

    // Helper to free memory and prevent leaks
    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                clear(node->children[i]);
            }
        }
        delete node;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Initialize root with a dummy index (0), will be corrected on the first insert
        root = new TrieNode(0);

        // Build the Trie
        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        // Process Queries
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& query : wordsQuery) {
            ans.push_back(search(query));
        }

        // Clean up memory
        clear(root);

        return ans;
    }
};