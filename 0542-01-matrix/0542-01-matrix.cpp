class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row[4] = {1,0,-1,0};
        int col[4] = {0,-1,0,1};
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int dis = it.second;
            for(int k = 0;k < 4;k++){
                int newr = r + row[k];
                int newc = c + col[k];
                if(newr >= 0 && newc >= 0 && newr < n && newc < m){
                    if(dis + 1 < dist[newr][newc]){
                        dist[newr][newc] = dis + 1;
                        q.push({{newr,newc},dis + 1});
                    }
                }
            }
        }
        return dist;
    }
};