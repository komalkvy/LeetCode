class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size(),num3=-1e9;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<num3) return 1;
            while(!st.empty() && nums[i]>st.top()){
                num3=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return 0;
    }
};