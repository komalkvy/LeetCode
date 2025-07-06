class Solution {
    void trav(TreeNode* root, vector<int> &in){
        if(!root) return;
        trav(root->left, in);
        in.push_back(root->val);
        trav(root->right, in);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> in;
        trav(root, in);
        return in[k-1];
    }
};