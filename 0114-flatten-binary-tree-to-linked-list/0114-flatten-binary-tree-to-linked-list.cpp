/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree
                TreeNode* last = curr->left;
                while (last->right != nullptr) {
                    last = last->right;
                }
                
                // Connection: Rightmost of left sub-tree points to current right
                last->right = curr->right;
                
                // Move left child to right and nullify left
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move on to the next node in the flattened path
            curr = curr->right;
        }
    }
};