#define ll long long
const int MOD = 1e9 + 7;
ll expo(ll a, ll b, ll m) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll tmp = expo(a, b/2, m);
    if (b&1) return (tmp*tmp%m)*a%m;
    return tmp*tmp%m;
}
struct SH {
    vector<ll> prefix;
    vector<ll> iBasePow;
    vector<ll> basePow;
    string s;
    SH(string &s) {
        this->s = s;
        int n = s.size();
        prefix.resize(n);
        iBasePow.resize(n);
        basePow.resize(n);
        hash();
    }
    void hash() {
        int cur;
        for (int i = 0; i < s.size(); i++) {
            basePow[i] = i == 0 ? 1 : basePow[i - 1] * 39 % MOD;
            cur = (s[i] - 'a' + 1);
            prefix[i] = i == 0 ? (cur * basePow[i] % MOD) : (prefix[i - 1] + cur * basePow[i] % MOD) % MOD;
        }
        iBasePow[0] = 1;
        if (s.size() > 1) {
            iBasePow[1] = expo(39,MOD-2,MOD);
            for (int i = 2; i < s.size(); i++) {
                iBasePow[i] = iBasePow[i - 1] * iBasePow[1] % MOD;
            }
        }
    }
    ll getHash(int l, int r) {
        ll l_h = l == 0 ? 0 : prefix[l - 1];
        ll r_h = prefix[r];
        ll res = r_h - l_h;
        res %= MOD;
        if (res < 0) res += MOD;
        res = (res * iBasePow[l]) % MOD;
        return res;
    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        SH h1(s);
        SH h2(goal);
        if (s == goal) return true;
        if (s.size() == 1) return false;
        for (int i = s.size() - 1; i>=1; i--) {
            int l1 = 0, r1 = i - 1;
            int l2 = r1 + 1, r2 = s.size() - 1;

            int ll1 = 0, rr1 = r2 - l2;
            int ll2 = r2 - l2 + 1, rr2 = s.size() - 1;
            if (h1.getHash(l1, r1) == h2.getHash(ll2, rr2) && h1.getHash(l2, r2) == h2.getHash(ll1, rr1)) {
                return true;
            }
        }
        return false;
    }
};