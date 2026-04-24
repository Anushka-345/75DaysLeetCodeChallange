class Trie {
private:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert word
    void insert(string word) {
        Node* temp = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (temp->children[idx] == NULL) {
                temp->children[idx] = new Node();
            }
            temp = temp->children[idx];
        }
        temp->isEnd = true;
    }

    // Search full word
    bool search(string word) {
        Node* temp = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (temp->children[idx] == NULL)
                return false;
            temp = temp->children[idx];
        }
        return temp->isEnd;
    }

    // Check prefix
    bool startsWith(string prefix) {
        Node* temp = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (temp->children[idx] == NULL)
                return false;
            temp = temp->children[idx];
        }
        return true;
    }
};