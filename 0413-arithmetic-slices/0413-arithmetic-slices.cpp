class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;

        int l=0,count=0;
        while(l+2<n)
        {
            int diff=nums[l+1]-nums[l];
            int r=l+1;
            while(r+1<n&&nums[r+1]-nums[r]==diff) r++;

            int length=r-l+1;
            if(length>=3)
            {
                int TempCount=(length-3+1)*(length-3+2)/2;
                count+=TempCount;
            }
            l=r;
        }
        return count;
    }
};