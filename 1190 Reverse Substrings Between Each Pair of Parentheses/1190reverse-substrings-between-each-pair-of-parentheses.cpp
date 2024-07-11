class Solution {
public:
    unordered_map<int,int> openClose;
    unordered_map<int,int> closeOpen;
    int n;
    string res = "";
    string reverseParentheses(string s) {
        n = s.size();
        vector<int> v;
        int top;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                v.push_back(i);
            } else if (s[i] == ')') {
                top = v.back(); v.pop_back();
                openClose[top] = i;
                closeOpen[i] = top;
            }
        }
        dfs(s, 0, n - 1, 0);
        return res;
    }
    void dfs(string &s, int i, int to, int mode) {
        if (mode == 0) {
            while (i <= to) {
                if (s[i] == '(') {
                    dfs(s, openClose[i] - 1, i + 1, 1);
                    i = openClose[i] + 1;
                } else {
                    res += s[i];
                    i++;
                }
            }
        } else {
            while (i >= to) {
                if (s[i] == ')') {
                    dfs(s, closeOpen[i] + 1, i - 1, 0);
                    i = closeOpen[i] - 1;
                } else {
                    res += s[i];
                    i--;
                }
            }
        }
    }
};