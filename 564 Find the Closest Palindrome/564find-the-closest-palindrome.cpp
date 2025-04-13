#define ll long long
class Solution {
public:

    ll mirror(ll x, bool odd) {
        string s = to_string(x);
        int len = odd ? s.size() * 2 - 1 : s.size() * 2;
        string res(len, ' ');
        for (int i = 0, j = len - 1; i <= j; i++, j--) {
            res[j] = res[i] = s[i];
        }
        return stoll(res);
    }
    string nearestPalindromic(string n) {
        int N = n.size();
        int half_N = (N + 1)/2;
        ll org = stoll(n);
        string half_s = n.substr(0, half_N);
        ll half = stoll(half_s);
        vector<ll> nums;
        nums.push_back(mirror(half - 1, N&1));
        nums.push_back(mirror(half + 1, N&1));
        ll tmp = mirror(half, N&1);
        if (tmp != org) nums.push_back(tmp);
        
        if (n[0] == '1') {
            if (N - 1 >= 1) {
                string s(N - 1, '9');
                nums.push_back(stoll(s));
            }
        } else {
            string s = n;
            s[0] = s[N - 1] = n[0] - 1;
            for (int i = 1; i < N - 1; i++) s[i] = '0';
            nums.push_back(stoll(s));
        }

        if (n[0] == '9') {
            string s(N + 1, '0');
            s[0] = s[N] = '1';
            nums.push_back(stoll(s));
        } else {
            string s(N, '0');
            s[0] = s[N - 1] = n[0] + 1;
            nums.push_back(stoll(s));
        }

        ll dif = 1e18 + 5, idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (dif > abs(nums[i] - org)) {
                dif = abs(nums[i] - org);
                idx = i;
            } else if (dif == abs(nums[i] - org) && nums[idx] > nums[i]) {
                idx = i;
            }
        }
        return to_string(nums[idx]);
    }
};