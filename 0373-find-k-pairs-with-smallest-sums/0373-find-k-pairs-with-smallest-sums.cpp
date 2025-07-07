class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n = nums1.size(), m = nums2.size();
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0, p = min(n, k); i < p; ++i) pq.emplace(nums1[i] + nums2[0], i, 0);
        while (!pq.empty() && res.size() < k) {
            auto [sum, i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < m) pq.emplace(nums1[i] + nums2[j + 1], i, j + 1);
        }
        return res;
    }
};