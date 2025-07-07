class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) {
            return 0;
        }

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] < k) {
                int leftPart = longestSubstring(s.substr(0, i), k);
                int rightPart = longestSubstring(s.substr(i + 1), k);
                return max(leftPart, rightPart);
            }
        }

        return s.size();
    }
};