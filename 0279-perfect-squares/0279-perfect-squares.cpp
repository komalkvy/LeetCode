class Solution {
public:

int fun(int idx,int k,vector<int>& vec,int tar,vector<vector<int>>&dp){
    if(idx==k){
      return INT_MAX;
    }
 if(tar==0) return 0;
 if(dp[idx][tar] !=-1) return dp[idx][tar];
     int tk=1e7;
    if(tar >=vec[idx]){
    
     tk= 1+ fun(idx,k,vec,tar-vec[idx],dp);
    
    }
   int nt= fun(idx+1,k,vec,tar,dp);
   return  dp[idx][tar]=min(nt,tk);
}
    int numSquares(int n) {
        if(n==1) return 1;
       
         int k=int(sqrt(n));
         
         vector<int>vec;
         for(int i=1; i<=k; i++){
            vec.push_back(i*i);
         }
         for(auto it: vec){
            cout<<it<<" ";
         }
         cout<<endl;
         //vector<int>temp;
         vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
         int idx=0;
       return   fun(idx,k,vec,n,dp);
        
    }
};