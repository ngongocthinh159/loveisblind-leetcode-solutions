#define ll long long
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        set<int> S;
        for (int i = 0; i < k; i++) S.insert(i);
        vector<int> cnt(k);
        int mx = -1;
        for (int i = 0; i < arrival.size(); i++) {
            while (pq.size() && pq.top().first <= arrival[i]) {
                auto p = pq.top(); pq.pop();
                S.insert(p.second);
            }
            if (S.size() == 0) {
                continue;
            }

            int idx = i%k;
            auto it = S.lower_bound(idx);
            int x;
            if (it == S.end()) {
                it = S.begin();
            }
            x = *it;
            cnt[x]++;
            mx = max(mx, cnt[x]);
            pq.push({arrival[i] + load[i], x});
            S.erase(it);
        }
        vector<int> res;
        for (int i = 0; i < k; i++) if (cnt[i] == mx) res.push_back(i);
        return res;
    }
};