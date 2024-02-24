class Solution {
public:
    struct comparator {
        bool operator() (const pair<int,int>&p1, const pair<int,int>&p2) const {
            return p1.second < p2.second;
        }
    };
    struct comparator2 {
        bool operator() (const pair<int,int>&p1, const pair<int,int>&p2) const {
            return p2.second < p1.second;
        }
    };
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> g(n);
        for (auto &m : meetings) {
            g[m[0]].push_back({m[1], m[2]});
            g[m[1]].push_back({m[0], m[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator2> q;
        q.push({0,0});
        q.push({firstPerson,0});
        set<int> S;
        vector<bool> visited(n,false);
        vector<int> ans;
        while (q.size()) {
            auto p = q.top(); q.pop();
            int u = p.first;
            int w_u = p.second;
            if (visited[u]) continue;
            visited[u] = true;
            ans.push_back(u);
            for (auto &p : g[u]) {
                int v = p.first;
                int w_v = p.second;
                if (w_v >= w_u) {
                    q.push({v,w_v});
                }    
            }
        }
        return ans;
    }
};