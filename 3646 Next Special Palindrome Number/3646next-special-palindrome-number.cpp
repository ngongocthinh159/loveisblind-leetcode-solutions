#define N 5000005
bool vis[10]{};
long long buf[N];
int top = 0;
void add(vector<int> &v) {
    string s = "";
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i]/2; j++) {
            s += v[i] + '0';
        }
    }
    string t = s;
    do {
        string cur = t;
        if (v.back() & 1) cur += v.back() + '0';
        for (int i = t.size() - 1; i >= 0; i--) cur += t[i];
        buf[top++] = stoll(cur);
        next_permutation(t.begin(), t.end());
    } while (t != s);
}
void dfs(vector<int> &v, int sum) {
    if (sum != 0) {
        add(v);
    }
    for (int i = 1; i <= 9; i += 2) if (sum + i <= 16) {
        v.push_back(i);
        add(v);
        v.pop_back();
    }
    for (int i = 2; i <= 8; i += 2) if (!vis[i] && sum + i <= 16) {
        vis[i] = 1;
        v.push_back(i);
        dfs(v, sum + i);
        v.pop_back();
        vis[i] = 0;
    }
}
auto init = []{
    vector<int> v;
    dfs(v, 0);
    sort(buf, buf + top);
    return false;
}();
class Solution {
public:
    long long specialPalindrome(long long n) {
        auto idx = upper_bound(buf, buf + top, n) - buf;
        return buf[idx];
    }
};  