class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> surf(n + 2);
        for (int i = n - 1; i >= 0; i--) {
            surf[i + 1] = surf[i + 2] + (s[i] == 'a');
        }
        int bcnt = 0;
        int ans = surf[1];
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') bcnt++;
            ans = min(ans, bcnt + (i + 1 < n ? surf[i + 2] : 0));
        }
        return ans;
    }
};