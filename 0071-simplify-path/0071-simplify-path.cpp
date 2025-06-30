class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        stack<string> st;
        
        for(int i=0;i<path.length();i++){
            if(path[i]=='/')    continue;
            string temp;
            //find the unique folder names
            while(i<path.length() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            //Ignore the current path
            if(temp=="."){
                continue;
            }
            //Remove the last folder
            else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            //otherwise push folder into stack
            else{
                st.push(temp);
            }
        }
        // Create a path name from traversing the stack 
        while(!st.empty()){
            ans = "/"+ st.top()+ ans;
            st.pop();
        }
        if(ans.length()==0) return "/";
        return ans;
    }
};