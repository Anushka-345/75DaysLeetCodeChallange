class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        stack<TreeNode*> currentLevel;
        stack<TreeNode*> nextLevel;
        
        currentLevel.push(root);
        bool leftToRight = true;

        while (!currentLevel.empty()) {
            vector<int> level;
            int size = currentLevel.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = currentLevel.top();
                currentLevel.pop();
                level.push_back(node->val);

                if (leftToRight) {
                    if (node->left) nextLevel.push(node->left);
                    if (node->right) nextLevel.push(node->right);
                } else {
                    if (node->right) nextLevel.push(node->right);
                    if (node->left) nextLevel.push(node->left);
                }
            }

            result.push_back(level);
            // Swap stacks and toggle direction
            currentLevel = move(nextLevel);
            leftToRight = !leftToRight;
        }

        return result;
    }
};