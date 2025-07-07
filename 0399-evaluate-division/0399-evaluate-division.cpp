#include <vector>
#include <unordered_map>
#include <string>
#include <string_view>

using namespace std;

class DisjointSet {
public:
    vector<int> size, rank;
    vector<pair<int, double>> parent;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = {i, 1.0};
    } 

    pair<int, double> findParent(int node) {
        auto& it = parent[node];
        if (node != it.first) {
            auto x = findParent(it.first);
            it.first = x.first;
            it.second *= x.second;
        }
        return it;
    }  

    void unionByRank(int u, int v, double val) {
        auto [ulp_u, val_u] = findParent(u);
        auto [ulp_v, val_v] = findParent(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = {ulp_v, val * val_v / val_u};
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = {ulp_u, val_u / val_v / val};
        } else {
            parent[ulp_u] = {ulp_v, val * val_v / val_u};
            rank[ulp_v]++;
        }
    }  

    void unionBySize(int u, int v, double val) {
        auto [ulp_u, val_u] = findParent(u);
        auto [ulp_v, val_v] = findParent(v); 

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] <= size[ulp_v]) {
            parent[ulp_u] = {ulp_v, val * val_v / val_u};
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = {ulp_u, val_u / val_v / val};
            size[ulp_u] += size[ulp_v];
        }
    }
};

class stringId {
public:
    int id_count = 0;
    unordered_map<string_view, int> store;

    int getId(string_view s) {
        int& id = store[s];
        if (id == 0) {
            id = ++id_count;
        }
        return id;
    }

    int maxi() const {
        return id_count;
    } 
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equa, vector<double>& values, vector<vector<string>>& quer) {
        stringId string_id;
        int n = equa.size();
        DisjointSet ds(n * 2 + 1);

        for (int i = 0; i < n; i++) {
            int a = string_id.getId(equa[i][0]);
            int b = string_id.getId(equa[i][1]);
            ds.unionBySize(a, b, values[i]);
        }

        int max_id = string_id.maxi();
        int m = quer.size();
        vector<double> ans(m, -1.0);

        for (int i = 0; i < m; i++) {
            int c = string_id.getId(quer[i][0]);
            if (c > max_id) continue;

            int d = string_id.getId(quer[i][1]);
            if (d > max_id) continue;

            auto [par_c, val_c] = ds.findParent(c);
            auto [par_d, val_d] = ds.findParent(d);

            if (par_c != par_d) continue;
            ans[i] = val_c / val_d;
        }

        return ans;
    }
};