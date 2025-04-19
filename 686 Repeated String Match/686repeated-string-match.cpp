#define N 500005
int z[N];
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        /*
            Imagine we wrote S = A+A+A+.... If B is to be a substring of S, we only need 
            to check  whether some S[0:], S[1:], ..., S[len(A) - 1:] starts with B, 
            as S is long enough to contain B, and S has a period at most len(A).
        */
        int n = a.size(), m = b.size();
        string s = "";
        while ((int) s.size() < n - 1 + m) s += a;
        string t = b + '#' + s;
        int T = t.size();
        for (int i = 1, l = 0, r = 0; i < T; i++) {
            z[i] = 0;
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < T && t[z[i]] == t[i + z[i]]) ++ z[i];
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
            if (i >= m + 1 && z[i] >= m)
                return (i - (m + 1) + m + n - 1) / n;
        }
        return -1;
    }
};