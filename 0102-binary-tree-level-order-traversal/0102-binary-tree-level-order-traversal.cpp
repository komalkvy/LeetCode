class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);  // \U0001f310 Level end marker
        vector<vector<int>> result;
        vector<int> level;

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (!node) {
                result.push_back(level);  // ✅ Save current level
                level.clear();
                if (!q.empty()) q.push(nullptr);  // ➕ Add marker for next level
            } else {
                level.push_back(node->val);  // \U0001f4e5 Visit node
                if (node->left) q.push(node->left);   // ⬅️ Left
                if (node->right) q.push(node->right); // ➡️ Right
            }
        }

        return result;
    }
};