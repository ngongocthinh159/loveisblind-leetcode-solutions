class Solution {
public:
    struct compare {
        bool operator() (const vector<int> &v1, const vector<int> &v2) const {
            return v2[0] < v1[0];
        }
    };
    int cost(int i, int I, int n) {
        int stepBetween = abs(i - I);
        int stepAround = n - stepBetween;
        return min(stepBetween, stepAround);
    }
    vector<int> move = {-1,1};
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> v(26);
        for (int i = 0; i < n; i++) {
            v[ring[i] - 'a'].push_back(i);
        }
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        vector<vector<int>> dist(n, vector<int>(m + 100, INT_MAX));
        dist[0][0] = 0;
        pq.push({0,0,0});
        while (pq.size()) {
            auto cur = pq.top(); pq.pop();
            int w_u = cur[0];
            int i = cur[1];
            int j = cur[2];
            if (j >= m) continue;
            int J = j + 1;
            for (auto &I : v[key[j] - 'a']) {
                if (J < m + 1 && dist[I][J] > w_u + 1 + cost(i, I, n)) {
                    dist[I][J] = w_u + 1 + cost(i, I, n);
                    pq.push({dist[I][J], I, j + 1});
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dist[i][m]);
        }
        return ans;
    }
};