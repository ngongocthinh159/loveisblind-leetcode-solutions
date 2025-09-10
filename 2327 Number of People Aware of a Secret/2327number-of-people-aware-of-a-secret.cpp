class Solution {
public:
    const int MOD = 1e9 + 7;
    void add(long long &x, long long y) {
        x += y;
        if (x >= MOD) x -= MOD;
        if (x < 0) x += MOD;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> startSharing(n + 1), stopForget(n + 1);
        long long know = 1, sharing = 0;
        if (1 + delay <= n) add(startSharing[1 + delay], 1);
        if (1 + forget <= n) add(stopForget[1 + forget], -1);
        for (int i = 2; i <= n; i++) {
            add(sharing, startSharing[i]);
            add(sharing, stopForget[i]);
            if (i + delay <= n) add(startSharing[i + delay], sharing);
            if (i + forget <= n) add(stopForget[i + forget], -sharing);
            add(know, sharing);
            add(know, stopForget[i]);
        }
        return know;
    }
};