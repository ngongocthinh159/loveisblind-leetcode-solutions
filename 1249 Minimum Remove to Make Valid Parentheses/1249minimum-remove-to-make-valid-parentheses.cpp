class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        stack<pair<char,int>> S;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if ('a' <= c && c <= 'z') continue;
            else if (c == '(') {
                S.push({c, i});
            } else {
                if (S.size()) {
                    S.pop();
                } else {
                    s[i] = '#';
                }
            }
        }
        while (S.size()) {
            s[S.top().second] = '#';
            S.pop();
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') continue;
            res += s[i];
        }
        return res;
    }
};