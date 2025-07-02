class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            TreeNode* left = root->left;
            TreeNode* temp = left;

            while (temp->right) temp = temp->right;

            temp->right = root->right;
            root->right = left;
            root->left = nullptr;
        }

        flatten(root->right);
    }
};