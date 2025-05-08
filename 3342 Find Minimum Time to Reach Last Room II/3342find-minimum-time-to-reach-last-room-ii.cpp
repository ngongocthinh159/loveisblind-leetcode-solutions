#define ll long long
class Solution {
public:
    const ll LINF = 1e18 + 5;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<ll>> dist(n, 
            vector<ll>(m, LINF));
        dist[0][0] = 0;
        set<pair<ll, pair<int,int>>> S;
        S.insert({0,{0,0}});
        while (S.size()) {
            auto p = *S.begin();
            S.erase(S.begin());
            ll w_u = p.first;
            int i = p.second.first;
            int j = p.second.second;
            for (int dx : {-1,0,1}) {
                for (int dy : {-1,0,1}) if (abs(dx) != abs(dy)) {
                    int I = i + dx;
                    int J = j + dy;
                    if (0 <= I && I < n && 0 <= J && J < m) {
                        ll w_uv = ((i&1)^(j&1)) + 1;
                        ll w_v = max(w_u + w_uv, moveTime[I][J] + w_uv);
                        if (w_v < dist[I][J]) {
                            S.erase({dist[I][J], {I, J}});
                            dist[I][J] = w_v;
                            S.insert({dist[I][J], {I, J}});
                        }
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};