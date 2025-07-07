class Solution {
public:
    int lengthLongestPath(string str) {
        
        int maxi = 0;
        stack<pair<int,int>> st;
        int ind = 0;
        int n = str.size();
        stringstream data(str);
        string temp;
        while(getline(data,temp,'\n')){
            int i = 0;
            while(temp[i]=='\t'){
                i++;
            }
            int num = i;
            while(!st.empty() and st.top().first>=num){
                st.pop();
            }
            int prev = 0;
            if(!st.empty()) prev = st.top().second+1;
            int curr = temp.size()-num;
            auto found = temp.find('.');
            if (found!=std::string::npos){
                maxi = max(maxi,prev+curr);
            }
            st.push({num,prev+curr});
        }
        return maxi;
    }
};