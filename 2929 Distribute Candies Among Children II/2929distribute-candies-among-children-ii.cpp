class Solution {
public:
    pair<int,int> intersect(int x1, int y1, int x2, int y2) {
        if (x1 > y2 || x2 > y1) 
            return {-1, -1};
        return {max(x1,x2), min(y1,y2)};
    }
    long long distributeCandies(int n, int limit) {
        int mxDis2 = min(n, 2*limit);
        int mnDis2 = n - min(limit, n);
        if (mnDis2 > mxDis2) return 0;
        // cout << mnDis2 << ' ' << mxDis2 << '\n';

        long long ans = 0;
        auto p1 = intersect(0, limit, mnDis2, mxDis2);
        if (p1.first != -1) {
            // cout << "here" << '\n';
            int len = p1.second - p1.first + 1;
            ans += 1LL * (p1.second + p1.first) * len / 2 + len;
        }
        auto p2 = intersect(limit + 1, 2*limit, mnDis2, mxDis2);
        if (p2.first != -1) {
            // cout << p2.first << ' ' << p2.second << '\n';
            int len = p2.second - p2.first + 1;
            ans += 1LL* 2 * len * limit - 1LL*(p2.second + p2.first) * len / 2 + len;
        }
        return ans;
    }
};