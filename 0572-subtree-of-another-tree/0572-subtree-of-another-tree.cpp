class Solution {
public:
    // Check if two trees are identical
    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSame(p->left, q->left) &&
               isSame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        // If match found
        if (isSame(root, subRoot)) return true;

        // Otherwise search left & right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};