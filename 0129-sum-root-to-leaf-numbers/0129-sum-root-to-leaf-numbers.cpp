class Solution {
    vector<string> ans;
    void trav(TreeNode* root, string s, string prev){
        if(!root) return;
        prev = s;
        s = s + to_string(root->val);
        if(!root->left && !root->right) ans.push_back(s);
        trav(root->left, s, prev);
        trav(root->right, s, prev);
        s = prev;
    }
public:
    int sumNumbers(TreeNode* root) {
        string s = "", prev= "";
        trav(root, s, prev);
        int sol = 0;
        for(auto n: ans)  sol += stoi(n);
        return sol;
    }
};