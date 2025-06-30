class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindices = 0;        // The farthest index we can currently reach
        int n = nums.size();       

        for(int i = 0; i < n; i++) {
            // If current index is beyond the farthest reachable index, we cannot proceed
            if(i > maxindices) return false;

            // Update the farthest reachable index from the current position
            maxindices = max(maxindices, i + nums[i]);
        }

        // If we completed the loop, we can reach the last index
        return true;
    }
};