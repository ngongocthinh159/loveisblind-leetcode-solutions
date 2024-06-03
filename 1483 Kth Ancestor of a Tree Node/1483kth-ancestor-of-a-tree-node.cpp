#define LOG 17
class TreeAncestor {
public:
    vector<vector<int>> g;
    vector<int> height;
    vector<vector<int>> par;
    TreeAncestor(int n, vector<int>& parent) {
        par = vector<vector<int>>(n, vector<int>(LOG + 1));
        g = vector<vector<int>>(n);
        height = vector<int>(n);

        int root;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {root = i; continue;}
            g[i].push_back(parent[i]);
            g[parent[i]].push_back(i);
        }
        dfs(root, -1, par);
    }

    void dfs(int u, int p, vector<vector<int>> &par) {
        for (auto &v : g[u]) {
            if (v != p) {
                height[v] = height[u] + 1;
                
                par[v][0] = u;
                for (int i = 1; i <= LOG; i++) {
                    par[v][i] = par[par[v][i - 1]][i - 1];
                }
                
                dfs(v, u, par);
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (height[node] < k) return -1;
        for (int i = LOG; i >= 0; i--) {
            if (k & (1 << i)) node = par[node][i];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */