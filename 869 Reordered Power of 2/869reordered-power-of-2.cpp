vector<vector<int>> v;
const int MOD = 1e9 + 7;
long long base = 128;
unordered_set<int> S;
int get(int n) {
    vector<int> freq(10);
    while (n) {
        freq[n%10]++;
        n /= 10;
    }
    long long h = 0;
    long long mul = 1;
    for (int i = 0; i < 10; i++) {
        h = (h + mul * (freq[i] + 1) * (i + 1) % MOD) % MOD;
        mul = mul * base % MOD;
    }
    return h;
}
auto init = []{
    long long cur = 1;
    while (cur <= 1e9) {
        S.insert(get(cur));
        cur = cur * 2;
    }
    return false;
}();
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        return S.count(get(n));
    }
};