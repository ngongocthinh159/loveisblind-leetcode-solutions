class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cnt_x = 0, cnt_y = 0, cnt_xy = 0, cnt_yx = 0;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'x') cnt_x++;
            else cnt_y++;
            if (s2[i] == 'x') cnt_x++;
            else cnt_y++;
            if (s1[i] == 'x' && s2[i] == 'y') cnt_xy++;
            if (s1[i] == 'y' && s2[i] == 'x') cnt_yx++;
        }
        if (cnt_x&1 || cnt_y&1) return -1;
        int ans = 0;
        ans += cnt_xy/2;
        cnt_xy %= 2;
        ans += cnt_yx/2;
        cnt_yx %= 2;
        if (cnt_xy) ans += 2;
        return ans;
    }
};