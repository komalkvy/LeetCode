class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transposing the matrix , making the columns = rows
        for(int i =0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // reversing each row 
        for(int i =0;i<n;i++){
            int start =0,end = n-1;
            while(start<end){
                swap(matrix[i][start],matrix[i][end]);
                start++,
                end--;
            }
        }
    }
};