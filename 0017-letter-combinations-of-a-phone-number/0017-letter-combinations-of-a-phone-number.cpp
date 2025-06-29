class Solution {
public:
    void f(int i, string &s,vector<string>& ans,string digits, unordered_map<char,string>& mpp){
        
        if(i==digits.size()){
            ans.push_back(s);
            return ;
        }

        string temp = mpp[digits[i]];
        for(char c: temp){
            s.push_back(c);
            f(i+1,s,ans,digits,mpp);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        unordered_map<char, string> mpp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        string s;
        f(0,s,ans,digits,mpp);
        return ans;
    }
};