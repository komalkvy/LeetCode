struct lamda{
    bool operator()(vector<int> &a,vector<int>&b){
        return a[0]<b[0];
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        int start=newInterval[0];
        int end=newInterval[1];
        vector<vector<int>> ans;
        for(int i=0;i<interval.size();i++){
            // Overlap from left
            if(start>=interval[i][0] && start <=interval[i][1]){
                start=min(start,interval[i][0]);
                end=max(end,interval[i][1]);
                continue;
            }
            //overlap from right
            if(end>=interval[i][0] && end<=interval[i][1]){
                start=min(start,interval[i][0]);
                end=max(end,interval[i][1]);
                continue;
            }
            // Full containment
            if(start<=interval[i][0] && end>=interval[i][1]){
                start=min(start,interval[i][0]);
                end=max(end,interval[i][1]);
                continue;
            }
            //no overlap
            ans.push_back({interval[i][0],interval[i][1]});
        }
        ans.push_back({start,end});  //insert new interval befor sorting
        sort(ans.begin(),ans.end(),lamda()); //sort based on first value
        return ans;
        
    }
};