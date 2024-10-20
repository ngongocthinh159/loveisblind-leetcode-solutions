class Solution {
public:
    unordered_map<int,int> M;
    bool parseBoolExpr(string s) {
        vector<char> v;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',' || s[i] == '(') continue;
            if (s[i] == '!' || s[i] == '&' || s[i] == '|' || s[i] == 't' || s[i] == 'f') v.push_back(s[i]);
            if (s[i] == ')') {
                bool hasTrue = false;
                bool hasFalse = false;
                while (v.back() != '!' && v.back() != '|' && v.back() != '&') {
                    if (v.back() == 't') hasTrue = true;
                    if (v.back() == 'f') hasFalse = true;
                    v.pop_back();
                }
                bool res;
                char op = v.back(); v.pop_back();
                if (op == '&') {
                    if (hasFalse) res = false;
                    else res = true;
                } else if (op == '|') {
                    if (hasTrue) res = true;
                    else res = false;
                } else {
                    if (hasTrue) res = false;
                    else res = true;
                }
                v.push_back(res ? 't' : 'f');
            }
        }
        return v[0] == 't' ? true : false;
    }
};