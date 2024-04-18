class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int i = 0;
        vector<string> ans;
        while (i < n) {
            vector<string> v;
            string res = "";
            v.push_back(words[i]);
            int len = words[i].size();
            int wordLen = words[i].size();
            while (i + 1 < n && len + words[i + 1].size() + 1 <= maxWidth) {
                len = len + words[i + 1].size() + 1;
                wordLen += words[i + 1].size();
                v.push_back(words[i + 1]);
                i++;
            }
            int wordCnt = v.size();
            if (i == n - 1) {
                for (int j = 0; j < v.size(); j++) {
                    res += v[j];
                    if (j != v.size() - 1) res += ' ';
                }
                string tmp(maxWidth - res.size(), ' ');
                res += tmp;
            } else {
                if (wordCnt == 1) {
                    res += v[0];
                    string tmp(maxWidth - res.size(), ' ');
                    res += tmp;
                } else {
                    int sep = (maxWidth - wordLen)/(wordCnt - 1);
                    int sepHas = maxWidth - wordLen - sep*(wordCnt - 1);
                    for (int j = 0; j < v.size(); j++) {
                        res += v[j];
                        if (j != v.size() - 1) {
                            string tmp(sep, ' ');
                            res += tmp;
                            if (sepHas) {
                                res += " ";
                                sepHas--;
                            }
                        }
                    }

                }
            }
            
            ans.push_back(res);   
            i++;
        }
        return ans;
    }
};