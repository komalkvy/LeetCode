class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long pref = 1, suff = 1;
        int maxpro = INT_MIN;
        int i = 0, j = n-1;
        while(i<n && j>=0){
            if (pref == 0) pref = nums[i];
            else pref *= nums[i];

            if (suff == 0) suff = nums[j];
            else   suff *= nums[j];

            long long ans = max(pref, suff);
            maxpro = max(maxpro, (int)ans);
            i++, j--;


        }
        return maxpro;

        // for (int i = 0; i<n; i++){
        //     int curpro = 1;
        //     for (int j = i; j<n; j++){
        //         curpro *= nums[j];
        //         maxpro = max(maxpro, curpro);
        //     }
        // }
        // return maxpro;



        // int currpro = 1;
        // int maxpro = INT_MIN;
        // for (int i = 0; i<n; i++){ 
        //     currpro *= nums[i];
        //     if (nums[i]==0){
        //         currpro = nums[i];
        //     }
        //     maxpro = max(maxpro, currpro);
        // }
        // return maxpro;
        
    }
};