class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int top=0;
        int bottom=a.size()-1;
        int left=0;
        int right=a[0].size()-1;
        while(top <=bottom && left <= right){
            int x=a[top][right];
            if(x==target){
                return true;
            }
            if(x<target){
                top++;
            }
            else{
                right--;
            }
        }
        return false;
    }
};