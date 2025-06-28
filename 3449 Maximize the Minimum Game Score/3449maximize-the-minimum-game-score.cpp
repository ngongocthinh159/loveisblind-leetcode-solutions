class Solution {
public:
    bool check(long long X, vector<int> &points, long long moves) {
        long long visitI = 0, usedMoves = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            long long requiredMovesI = (X + points[i] - 1) / points[i];
            long long remainMovesI = max(0LL, requiredMovesI - visitI);
            long long takeMoves = max(0LL, 2 * remainMovesI - 1);
            usedMoves += takeMoves;
            visitI = max(0LL, remainMovesI - 1);
            if (takeMoves == 0 && i != n - 1) 
                usedMoves++;
            if (usedMoves > moves)
                return false;
        }
        return true;
    }
    long long maxScore(vector<int>& points, int m) {
        int n = points.size();
        long long l = 0, r = 1e18 + 1;
        while (r - l > 1) {
            long long mid = l + (r - l)/2;
            if (check(mid, points, m))
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};