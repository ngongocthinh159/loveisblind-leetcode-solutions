#define MAX 10005
vector<bool> prime(MAX, true);
auto init = [] {
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX; i++) if (prime[i])
        for (int j = i*i; j < MAX; j += i) prime[j] = false;
    return 0;
}();
class Solution {
public:
    int minOperations(int n, int m) {
        if (prime[n] || prime[m]) return -1;
        set<pair<int,int>> S;
        unordered_map<int,int> dist;
        S.insert({n, n});
        while (S.size()) {
            auto p = *S.begin();
            S.erase(S.begin());

            int w_u = p.first;
            int u = p.second;
            if (u == m) return w_u;
            
            string s = to_string(u);
            vector<int> neis;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != '0') {
                    if (i != 0 || s[i] != '1') {
                        s[i]--;
                        int v = stoi(s);
                        neis.push_back(v);
                        s[i]++;
                    }
                }
                if (s[i] != '9') {
                    s[i]++;
                    int v = stoi(s);
                    neis.push_back(v);
                    s[i]--;
                }
            }
            for (auto v : neis) {
                if (!prime[v] && (!dist.count(v) || dist[v] > w_u + v)) {
                    S.erase({dist[v], v});
                    dist[v] = w_u + v;
                    S.insert({dist[v], v});
                }
            }
        }
        return -1;
    }
};