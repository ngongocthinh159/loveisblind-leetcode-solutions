class Solution {
public:
    string simplifyPath(string s) {
        vector<string> v;
        int i = 1;
        while (i < s.size()) {
            if (s[i] == '/') {
                while (i < s.size() && s[i] == '/') i++;
            } else {
                string name = "";
                while (i < s.size() && s[i] != '/') {
                    name += s[i];
                    i++;
                }
                if (name == ".") {

                } else if (name == "..") {
                    if (v.size()) v.pop_back();
                } else {
                    v.push_back(name);
                }
            }
        }
        string res = "/";
        for (int j = 0; j < v.size(); j++) {
            if (j != 0) res += '/';
            res += v[j];
        }
        return res;
    }
    
};