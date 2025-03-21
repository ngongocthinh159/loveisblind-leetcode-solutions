class Solution {
public:
    unordered_map<string,vector<string>> g;
    unordered_set<string> sup;
    unordered_map<string,int> dp;
    // unordered_map<string,bool> active;
    int n;
    int dfs(string &u) {
        if (dp.count(u)) return dp[u];
        if (!g[u].size()) return sup.count(u);
        // active[u] = 1;
        int res = 1;
        for (auto &v : g[u]) {
            // if (active[v])
            //     return dp[u] = 0;
            // else 
                res &= dfs(v);
        }
        // active[u] = 0;
        return dp[u] = res;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        n = recipes.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < ingredients[i].size(); j++)
                g[recipes[i]].push_back(ingredients[i][j]);
        for (auto &x : supplies) sup.insert(x);
        for (int i = 0; i < n; i++) if (!dp.count(recipes[i])) dfs(recipes[i]);
        vector<string> res;
        for (int i = 0; i < n; i++) if (dp[recipes[i]] == 1) res.push_back(recipes[i]);
        return res;
    }
};