class Solution {
public:
    const int IINF = 1e9;
    int solve(vector<int> &tops, vector<int> &bottoms) {
        int n = tops.size(), ans = IINF;
        for (int j = 1; j <= 6; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (tops[i] == j) continue;
                if (bottoms[i] == j) cnt++;
                else {
                    cnt = IINF;
                    break;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int res = solve(tops, bottoms);
        res = min(res, solve(bottoms, tops));
        return res == IINF ? -1 : res;
    }
};