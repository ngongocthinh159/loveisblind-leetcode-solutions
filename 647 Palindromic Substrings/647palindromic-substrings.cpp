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
        if (odd) {
            int idx = 1 + 2*cenIdx;
            return this->P[idx] - 1;
        } else {
            int idx = 1 + 2*cenIdx - 1;
            return this->P[idx] - 1;
        }
    }
    
    // 0-based index
    bool isPalindrome(int l, int r) {
        return true;
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
    int countSubstrings(string s) {
        Manacher m(s);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += ceil((double) m.getLongest(i, true)/2);
            if (i>=1) ans += m.getLongest(i, false)/2;
        }
        return ans;
    }
};