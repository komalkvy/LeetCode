/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        
        while (root) {
            if (root->val > p->val && root->val > q->val) {
                // Both nodes lie in the left subtree
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                // Both nodes lie in the right subtree
                root = root->right;
            } else {
                // Split point found
                break;
            }
        }
        
        return root;
    }
};