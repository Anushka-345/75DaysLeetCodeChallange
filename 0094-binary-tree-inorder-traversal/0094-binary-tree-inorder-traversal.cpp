class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;
        
        inorder(root->left, res);   // Left
        res.push_back(root->val);   // Root
        inorder(root->right, res);  // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};