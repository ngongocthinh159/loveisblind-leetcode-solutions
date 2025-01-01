class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> scoreRight(n);
        for (int i = n - 1; i >= 0; i--) scoreRight[i] = (s[i] == '1' ? 1 : 0) + (i != n - 1 ? scoreRight[i + 1] : 0);
        int scoreLeft = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            scoreLeft += (s[i] == '0' ? 1 : 0);
            ans = max(ans, scoreLeft + scoreRight[i + 1]);
        }
        return ans;
    }
};