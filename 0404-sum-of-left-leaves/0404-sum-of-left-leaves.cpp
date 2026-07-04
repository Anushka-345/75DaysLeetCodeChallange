class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        
        int sum = 0;
        
        // Check if the left child exists and is a leaf node
        if (root->left && root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        }
        
        // Recursively calculate the sum for both left and right subtrees
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        
        return sum;
    }
};