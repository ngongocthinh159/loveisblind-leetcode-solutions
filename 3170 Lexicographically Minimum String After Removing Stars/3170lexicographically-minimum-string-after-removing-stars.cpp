class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int> removed(n);
        vector<vector<int>> cToIdx(26, vector<int>());
        set<int> S;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                cToIdx[s[i] - 'a'].push_back(i);
                S.insert(s[i] - 'a');
            }                
            else {
                removed[i] = 1;
                int c = *S.begin();
                removed[cToIdx[c].back()] = 1;
                cToIdx[c].pop_back();
                if (cToIdx[c].empty()) S.erase(c);
            }
        }
        string res = "";
        for (int i = 0; i< n; i++) if (!removed[i]) res+= s[i];
        return res;
    }
};