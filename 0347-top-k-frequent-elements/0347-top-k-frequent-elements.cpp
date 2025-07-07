class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; ++i) ++freq[nums[i]];
        vector<vector<int>> buckets(n + 1);
        for (const auto& [num, count] : freq) buckets[count].push_back(num);
        vector<int> result;
        for (int i = n; i >= 0; --i) {
            for (int j = 0, m = buckets[i].size(); j < m; ++j) result.push_back(buckets[i][j]);
            if (result.size() == k) break;
        }
        return result;
    }
};