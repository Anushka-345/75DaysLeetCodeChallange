class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        // Swap children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recurse
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};