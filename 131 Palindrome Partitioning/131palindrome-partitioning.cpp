struct Manacher {
    string s; // aabb
    vector<int> P; // #a#a#b#b#
    Manacher(string s) {
        this->s = s;
        preprocess();
    }

    void preprocess() {
        string t = "";
        for (auto c : this->s) {
            t += '#';
            t += c;
        }
        t += "#";
        this->P = manacher_odd(t);
    }

    vector<int> getPArray() {
        return this->P;
    }

    // 0-based index
    // Odd: cenIdx
    // Even (only cenIdx >= 1): cenIdx && cenIdx - 1 
    int getLongest(int cenIdx, bool odd) {
        int idx;
        if (odd) idx = 1 + 2*cenIdx;
        else idx = 1 + 2*cenIdx - 1;
        return this->P[idx] - 1;
    }
    
    // 0-based index
    bool isPalindrome(int l, int r) {
        return (r-l+1) <= getLongest((l+r+1)/2, l%2==r%2);
    }

    vector<int> manacher_odd(string s) {
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 0, r = 2;   
        for (int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + r - i]));    
            while (s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i]; r = i + p[i];
            }
        }
        return vector<int>(p.begin() + 1, p.end() - 1);
    }
};

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        Manacher mana(s);        
        dfs(0, s, mana);
        return res;
    }
    void dfs(int i, string &s, Manacher &mana) {
        if (i == s.size()) {
            res.push_back(path);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (mana.isPalindrome(i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, mana);
                path.pop_back();
            }
        }
    }
};