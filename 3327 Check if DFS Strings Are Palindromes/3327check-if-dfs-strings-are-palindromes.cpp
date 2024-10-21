struct Manacher {
    string s; // aabb
    vector<int> P; // #a#a#b#b#
    Manacher(string s) {
        this->s = s;
        preprocess();
    }

    void preprocess() {
        string t = "";
        for (auto c : this->s) {
            t += '#';
            t += c;
        }
        t += "#";
        this->P = manacher_odd(t);
    }

    vector<int> getPArray() {
        return this->P;
    }

    // 0-based index
    // Odd: cenIdx
    // Even (only cenIdx >= 1): cenIdx && cenIdx - 1 
    int getLongest(int cenIdx, bool odd) {
        int idx;
        if (odd) idx = 1 + 2*cenIdx;
        else idx = 1 + 2*cenIdx - 1;
        return this->P[idx] - 1;
    }
    
    // 0-based index
    bool isPalindrome(int l, int r) {
        return (r-l+1) <= getLongest((l+r+1)/2, l%2==r%2);
    }

    vector<int> manacher_odd(string s) {
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 0, r = 2;   
        for (int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + r - i]));    
            while (s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i]; r = i + p[i];
            }
        }
        return vector<int>(p.begin() + 1, p.end() - 1);
    }
};

class Solution {
public:
    vector<vector<int>> g;
    vector<int> firstLeaf;
    int n;
    vector<int> dfsTime;
    vector<bool> findAnswer(vector<int>& parent, string s) {
        n = parent.size();
        g.resize(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) g[parent[i]].push_back(i);
        }
        firstLeaf.resize(n);
        getFirstLeaf(0);
        dfs(0);
        string t = "";
        unordered_map<int,int> M; // number to index in t
        for (int i = 0; i < dfsTime.size(); i++) {
            t += s[dfsTime[i]];
            M[dfsTime[i]] = i;
        }
        vector<bool> ans(n);
        Manacher mana(t);
        for (int i = 0; i < n; i++) {
            int end = M[i];
            int start = M[firstLeaf[i]];
            ans[i] = mana.isPalindrome(start, end);
        }
        return ans;
    } 
    int getFirstLeaf(int u) {
        int res = u;
        int i = 0;
        for (auto v : g[u]) {
            int tmp = getFirstLeaf(v);
            if (i == 0) res = tmp;
            i++;
        }
        return firstLeaf[u] = res;
    }
    void dfs(int u) {
        for (auto v : g[u]) {
            dfs(v);
        }
        dfsTime.push_back(u);
    }
};