class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1 , 0);
        dp[0] = 1;
        int n = nums.size();
        for(int i = 1; i <= target; ++i){
            for(int j = 0; j < n; ++j){
                if(i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};