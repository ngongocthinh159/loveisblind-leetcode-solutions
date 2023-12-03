class Solution {
public:
    int calculate(string s) {
        vector<string> v;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {i++; continue;}
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                string tmp = ""; tmp += s[i];
                v.push_back(tmp); i++;
            } else if ('0' <= s[i] && s[i] <= '9') {
                string cur = "";
                while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
                    cur += s[i++];
                }
                if (!v.size() || v.back() == "+" || v.back() == "-") v.push_back(cur);
                else {
                    string op = v.back(); v.pop_back();
                    string num = v.back(); v.pop_back();
                    string tmp;
                    if (op == "*") {
                        tmp = to_string(stoi(num)*stoi(cur));
                    } else {
                        tmp = to_string(stoi(num)/stoi(cur));
                    }
                    v.push_back(tmp);
                }
            }
        }

        int res = 0;
        for (int j = 0; j<v.size();) {
            if (j == 0) res += stoi(v[j++]);
            else {
                string op = v[j++];
                string strNum = v[j++];
                if (op == "+") res += stoi(strNum);
                if (op == "-") res -= stoi(strNum);
            }
        }
        return res;
    }
};