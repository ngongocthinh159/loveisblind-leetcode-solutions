class Solution {
public:
    int fillCups(vector<int>& amount) {
        int mn = min(amount[0], min(amount[1], amount[2]));
        int mx = max(amount[0], max(amount[1], amount[2]));
        int sc = amount[0]^amount[1]^amount[2]^mn^mx;
        int tmp = sc - mn;
        int ans = tmp;
        mx -= tmp;
        sc -= tmp;
        if (mx >= 2*mn) {
            ans += 2*mn;
            mx -= 2*mn;
            ans += mx;
        } else {
            int half = mx/2;
            int half2 = mx - half;
            mn -= half2;
            sc -= half;
            ans += half + half2;
            sc -= mn;
            ans += mn;
            ans += sc;
        }
        return ans;
    }
};