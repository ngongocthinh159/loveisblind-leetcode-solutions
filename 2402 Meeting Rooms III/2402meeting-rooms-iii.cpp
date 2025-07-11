#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        ll T = 0;
        vector<int> order((int)m.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return m[i][0] < m[j][0];
        });
        auto cmp = [](auto &p1, auto &p2) {
            return p2.first < p1.first;
        };
        auto cmp2 = [](int i, int j) {
            return j < i;
        };
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,decltype(cmp)> q(cmp);
        priority_queue<int,vector<int>,decltype(cmp2)> room(cmp2);
        for (int i = 0; i < n; i++) room.push(i);
        unordered_map<int,int> freq;
        int mx = 0, res = 1e9;
        for (int i = 0; i < (int) m.size(); ) {
            T = max(T, 1LL * m[order[i]][0]);
            while (q.size() && q.top().first <= T) {
                room.push(q.top().second);
                q.pop();
            }
            if (room.size()) {
                int usedRoom = room.top();
                room.pop();
                freq[usedRoom]++;
                if (freq[usedRoom] > mx) {
                    mx = freq[usedRoom];
                    res = usedRoom;
                } else if (freq[usedRoom] == mx) 
                    res = min(res, usedRoom);
                int len = m[order[i]][1] - m[order[i]][0];
                q.push({T + len, usedRoom});
                i++;
            } else {
                T = q.top().first;
            }
        }
        return res;
    }
};