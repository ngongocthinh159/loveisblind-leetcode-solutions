#define ll long long
class Solution {
public:
    ll encode(string &s) {
        ll res = 0;
        for (int i = 0; i < s.size(); i++) {
            ll num = s[i] - '0' + 1;
            res += num*pow(11, i);
        }
        return res;
    }
    vector<int> moves = {1,-1};
    int openLock(vector<string>& deadends, string target) {
        unordered_set<ll> S;
        for (auto &s : deadends) {
            S.insert(encode(s));
        }
        string src = "0000";
        if (S.count(encode(target)) || S.count(encode(src))) return -1;
        deque<string> q;
        q.push_front(src);
        S.insert(encode(src));
        int step = 0;
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto u = q.back(); q.pop_back();
                if (u == target) return step;
                for (int j = 0; j < u.size(); j++) {
                    for (auto &move : moves) {
                        string v = u;
                        char c = v[j];
                        c += move;
                        if (c > '9') c = '0';
                        else if (c < '0') c = '9';
                        v[j] = c;
                        if (!S.count(encode(v))) {
                            S.insert(encode(v));
                            q.push_front(v);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};