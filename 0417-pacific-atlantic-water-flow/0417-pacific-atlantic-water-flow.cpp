class Solution {
public:
    int drow[4]={1,-1,0,0};
    int dcol[4]={0,0,-1,1};

    void dfs(vector<vector<int>>&grid,vector<vector<bool>>&can,int i,int j,int m,int n){

        can[i][j]=true;

        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[i][j]<=grid[nrow][ncol] && !can[nrow][ncol]){
                dfs(grid,can,nrow,ncol,m,n);
            }
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //m * n matrix
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>>res;

        vector<vector<bool>>canPacific(m,vector<bool>(n,false));
        vector<vector<bool>>canAtlantic(m,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            canPacific[0][i]=true;
            canAtlantic[m-1][i]=true;
        }

        for(int i=0;i<m;i++){
            canPacific[i][0]=true;
            canAtlantic[i][n-1]=true;
        }
        //boundary analysis complete

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(canPacific[i][j]){
                    dfs(heights,canPacific,i,j,m,n);
                }
                if(canAtlantic[i][j]){
                    dfs(heights,canAtlantic,i,j,m,n);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(canPacific[i][j] && canAtlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;

    }
};