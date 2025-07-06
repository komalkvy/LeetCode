class Solution {
public:

    int noOfActiveCell(vector<vector<int>>& board, int r, int c) {
        int cnt = 0;
        for (int i = r - 1; i <= r + 1; i++) {
            for (int j = c - 1; j <= c + 1; j++) {
                if (i == r && j == c) continue;
                if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) {
                    if (board[i][j] == 1 || board[i][j]==-2) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                int l=noOfActiveCell(board,i,j);
                if(board[i][j]==0)
                {
                    if(l==3)
                    {
                        board[i][j]=2;
                    }
                    
                }
                else
                {
                    if(l<2 || l>3)
                    {
                        board[i][j]=-2;
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==2)
                    board[i][j]=1;
                if(board[i][j]==-2)
                    board[i][j]=0;
            }
        }        
    }
};