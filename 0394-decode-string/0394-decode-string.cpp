class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ']') {
                st.push(string(1, s[i]));
            } else {
                // Step 1: Build the substring
                string substr = "";
                while (!st.empty() && st.top() != "[") {
                    substr = st.top() + substr;
                    st.pop();
                }

                // Step 2: Pop the '['
                st.pop();

                // Step 3: Build the repeat count k
                string k_str = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    k_str = st.top() + k_str;
                    st.pop();
                }

                int k = stoi(k_str);
                string repeated = "";
                for (int j = 0; j < k; ++j) {
                    repeated += substr;
                }

                st.push(repeated);
            }
        }

        // Final result: concatenate everything from the stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};