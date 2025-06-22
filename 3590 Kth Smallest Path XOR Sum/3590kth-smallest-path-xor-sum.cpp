#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

struct Query {
    int k, idx;  
};

class Solution {
public:
    vector<vector<int>> g;
    int n;
    vector<vector<Query>> rootToQ;
    vector<int> ans;
    vector<pbds> subval;
    void dfs(int u, int xsum, vector<int> &vals) {
        subval[u].insert(xsum);
        for (auto v : g[u]) {
            dfs(v, xsum ^ vals[v], vals);
            merge(subval[u], subval[v]);
        }

        for (auto &q : rootToQ[u])
            ans[q.idx] = (int) subval[u].size() < q.k ? -1 : *subval[u].find_by_order(q.k - 1);
    }
    void merge(pbds &subu, pbds &subv) {
        if (subu.size() < subv.size()) subu.swap(subv);
        for (auto x : subv) subu.insert(x);
    }
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        n = par.size();
        int m = queries.size();
        g.resize(n);
        ans.resize(m);
        subval.resize(n);
        rootToQ.resize(n);
        for (int i = 1; i < n; i++) {
            g[par[i]].push_back(i);
        }
        for (int i = 0; i < m; i++) {
            rootToQ[queries[i][0]].push_back(Query{queries[i][1], i});
        }
        dfs(0, vals[0], vals);
        return move(ans);
    }
};