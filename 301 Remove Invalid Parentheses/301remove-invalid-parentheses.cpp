class Solution {
public:
    set<string> S;
    string path;
    vector<string> removeInvalidParentheses(string s) {
        
        int preClose = 0;
        int surOpen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') continue;
            if (s[i] == '(') {
                surOpen++;
            } else {
                if (surOpen > 0) surOpen--;
                else preClose++;
            }
        }
        // cout << preClose << " " << surOpen << "\n";
        dfs(0, s, 0, preClose, surOpen);
        return vector<string>(S.begin(), S.end());
    }
    void dfs(int i, string &s, int open, int remainClose, int remainOpen) {
        if (i == s.size()) {
            // for (auto c : path) {
            //     cout << c;
            // }
            // cout << "\n";
            // cout << open << " " << remainClose << " " << remainOpen << "\n";
            if (open == 0 && remainClose == 0 && remainOpen == 0) {
                if (!S.count(path)) {
                    S.insert(path);
                }
            }

            return;
        }

        if (s[i] == ')') {
            if (remainClose > 0) {
                dfs(i + 1, s, open, remainClose - 1, remainOpen);
            }
            
            if (open > 0) {
                path.push_back(s[i]);
                dfs(i + 1, s, open - 1, remainClose, remainOpen);
                path.pop_back();
            }
        } else if (s[i] == '(') {
            if (remainOpen > 0) {
                dfs(i + 1, s, open, remainClose, remainOpen - 1);
            }

            path.push_back(s[i]);
            dfs(i + 1, s, open + 1, remainClose, remainOpen);
            path.pop_back();
        } else {
            path += s[i];
            dfs(i + 1, s, open, remainClose, remainOpen);
            path.pop_back();
        }
    }
};