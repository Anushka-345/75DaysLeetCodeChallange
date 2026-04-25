class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool searchHelper(string &word, int i, TrieNode* node) {
        if (!node) return false;

        if (i == word.size())
            return node->isEnd;

        char c = word[i];

        if (c == '.') {
            // try all possibilities
            for (int j = 0; j < 26; j++) {
                if (node->children[j] &&
                    searchHelper(word, i + 1, node->children[j]))
                    return true;
            }
            return false;
        } else {
            int idx = c - 'a';
            return searchHelper(word, i + 1, node->children[idx]);
        }
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};