class Solution {
public:
    string to_lower(string &s) {
        string res = "";
        for (int i = 0; i< s.size(); i++) {
            if ('A' <= s[i] && s[i] <= 'Z')
                res += s[i] - 'A' + 'a';
            else
                res += s[i];
        }
        return res;
    }
    string generateTag(string caption) {
        string s = "";
        bool first = true;
        vector<string> v;
        for (int i = 0; i < caption.size();) {
            while (i < caption.size() && caption[i] == ' ') i++;
            string cur = "";
            while (i < caption.size() && caption[i] != ' ') {
                if (('a' <= caption[i] && caption[i] <= 'z') ||
                    ('A' <= caption[i] && caption[i] <= 'Z')) cur += caption[i];
                i++;
            }
            if (cur != "")
                v.push_back(cur);
        }
        string res = "";
        for (int i = 0; i < v.size(); i++) {
            string cur = to_lower(v[i]);
            if (!first) cur[0] = cur[0] - 'a' + 'A';
            res += cur;
            first = false;
        }
        res = "#" + res; 
        if (res.size() > 100)
            res = res.substr(0, 100);
        return res;
    }
};