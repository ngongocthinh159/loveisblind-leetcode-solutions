class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> ok1(26);
        vector<bool> ok2(26);
        for (auto c : word) {
            if ('a' <= c && c <= 'z') ok1[c-'a'] = true;
            else ok2[c-'A'] = true;
        }
        set<int> S;
        for (int i = 0; i < 26; i++) {
            if (ok1[i] && ok2[i]) {
                S.insert(i);
            }
        }
        vector<int> state(26,0);
        for (auto c : word) {
            int idx;
            if ('a' <= c && c <= 'z') {
                idx = c - 'a';
                if (state[idx] == 0) {
                    
                } else if (state[idx] == 1) {
                    if (S.count(idx)) S.erase(idx);
                }
                
            } else {
                int idx = c - 'A';
                if (state[idx] == 0) {
                    state[idx] = 1;
                } else if (state[idx] == 1) {
                    
                }
            }
        }
        return S.size();
    }
};