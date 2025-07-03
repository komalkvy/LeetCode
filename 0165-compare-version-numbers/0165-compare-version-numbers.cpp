class Solution {
public:
    int compare(vector<string>& arr1, vector<string>& arr2) {
        int n = arr1.size(), m = arr2.size();
        int len = max(n, m);

        for (int i = 0; i < len; ++i) {
            int n1 = (i < n) ? stoi(arr1[i]) : 0;
            int n2 = (i < m) ? stoi(arr2[i]) : 0;

            if (n1 < n2) return -1;
            if (n1 > n2) return 1;
        }

        return 0;
    }

    int compareVersion(string version1, string version2) {
        vector<string> arr1, arr2;
        string temp = "";

        // Split version1 into arr1
        for (char c : version1) {
            if (c == '.') {
                arr1.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        arr1.push_back(temp); // Add the last part

        temp = "";
        // Split version2 into arr2
        for (char c : version2) {
            if (c == '.') {
                arr2.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        arr2.push_back(temp); // Add the last part

        return compare(arr1, arr2);
    }
};