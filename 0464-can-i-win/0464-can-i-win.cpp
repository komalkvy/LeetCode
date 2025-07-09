class Solution {
public:
    bool canIWin(int maxc, int des) {
        int full=(1<<(maxc))-1;
        int maxsum=maxc*(maxc+1)/2;
        // If not possible to make desired sum even after using all values.
        if (maxsum<des)return false;
        vector<array<int,2>>dp(full+1,{-1,-1});
        // vector<vector<int>>dp(full+1,vector<int>(2,-1));
        auto dfs=[&](auto self,int mask,int turn)->bool{
            if (dp[mask][turn]!=-1)return dp[mask][turn];
            bool res;
            if (turn)res=true;
            else res=false;
            int allp=0;
            // Current reached sum.
            for(int i=1;i<=maxc;i++){
                if ((mask&(1<<(i-1)))==0)continue;
                allp+=i;
            }
            for(int i=1;i<=maxc;i++){
                if (mask&(1<<(i-1)))continue;
                if (allp+i>=des){
                    if (turn)return dp[mask][turn]=false;
                    return dp[mask][turn]=true;
                }
                else {
                    // Opponent turn
                    if (turn)res=res && self(self,mask|(1<<(i-1)),turn^1);
                    //Our turn
                    else res=res||self(self,mask|(1<<(i-1)),turn^1);
                }
            }
            return dp[mask][turn]=res;
        };
        bool got=false;
        for(int i=1;i<=maxc;i++){
            if (i>=des)return true;
            got=got || dfs(dfs,(1<<(i-1)),1);
        }
        return got;
    }
};