class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> akey(n), abox(n), vis(n);
        deque<int> q;
        for (auto x : initialBoxes) {
            abox[x] = 1;
            if (status[x]) q.push_front(x), vis[x] = 1;
        }
        int ans = 0;
        while (q.size()) {
            int u = q.back(); q.pop_back();
            ans += candies[u];
            for (auto x : containedBoxes[u]) {
                abox[x] = 1;
                if ((status[x] || akey[x]) && !vis[x]) q.push_front(x), vis[x] = 1;
            }
            for (auto x : keys[u]) {
                akey[x] = 1;
                if (abox[x] && !vis[x]) q.push_front(x), vis[x] = 1;
            }
        }
        return ans;
    }
};