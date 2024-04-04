class Solution {
public:
    int maxDepth(string s) {
        stack<char> S;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                S.push(s[i]);
                ans = max(ans, (int) S.size());
            } else if (s[i] == ')') {
                S.pop();
            }
        }
        return ans;
    }
};