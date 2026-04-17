class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both NULL
        if (p == NULL && q == NULL) return true;

        // Case 2: one NULL
        if (p == NULL || q == NULL) return false;

        // Case 3: value mismatch
        if (p->val != q->val) return false;

        // Check left and right
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};