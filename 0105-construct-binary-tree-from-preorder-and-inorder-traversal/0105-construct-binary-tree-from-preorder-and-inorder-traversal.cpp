class Solution {
    // Hash map to store inorder indices for O(1) lookup
    unordered_map<int, int> inorderIndexMap;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // The first element in preorder is the root
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root in inorder to split subtrees
        int inRoot = inorderIndexMap[rootVal];
        int leftSize = inRoot - inStart;

        // Recursively build the left and right subtrees
        root->left = build(preorder, preStart + 1, preStart + leftSize, 
                           inorder, inStart, inRoot - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, 
                            inorder, inRoot + 1, inEnd);

        return root;
    }
};