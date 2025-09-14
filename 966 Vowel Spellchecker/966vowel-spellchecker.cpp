class Solution {
public:
    unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u'};
    string to_lower(string &s) {
        string res = s;
        for (auto &x : res) x = tolower(x);
        return res;
    }
    string to_err(string &s) {
        string res = s;
        for (auto &x : res) if (vow.count(x)) x = '.';
        return res;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string,int> f;
        unordered_map<string,int> err;
        for (int i = wordlist.size() - 1; i >= 0; i--) {
            exact.insert(wordlist[i]);

            string s = to_lower(wordlist[i]);
            f[s] = i;
            err[to_err(s)] = i;
        }
        int m = queries.size();
        vector<string> ans(m);
        for (int i = 0; i < m; i++) {
            auto &q = queries[i];
            if (exact.count(q)) {
                ans[i] = q;
            } else {
                auto tmp = to_lower(q);
                if (f.count(tmp)) {
                    ans[i] = wordlist[f[tmp]];
                } else {
                    string err_s = to_err(tmp);
                    if (err.count(err_s))
                        ans[i] = wordlist[err[err_s]];
                }
            }
        }
        return ans;
    }
};