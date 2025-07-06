class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h_ind =0;
        int cnt=0;
        for(int i= citations.size()-1 ; i>=0 ;i-- ){
            if(citations[i] > cnt){
                h_ind++;
                cnt++;
            }
        }
        return h_ind;
    }
};