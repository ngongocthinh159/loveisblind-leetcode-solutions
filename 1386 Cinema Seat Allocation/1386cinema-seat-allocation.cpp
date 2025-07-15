int cnt[1 << 10];
auto init = []{
    for (int mask = 0; mask < (1 << 10); mask++) {
        if ((mask & 0b0111111110) == 0) cnt[mask] = 2;
        else if ((mask & 0b0111100000) == 0) cnt[mask] = 1;
        else if ((mask & 0b0000011110) == 0) cnt[mask] = 1;
        else if ((mask & 0b0001111000) == 0) cnt[mask] = 1;
    }
    return 0;
}();
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> rowToMask;
        for (auto &r : reservedSeats) {
            int i = r[0] - 1;
            int j = r[1] - 1;
            rowToMask[i] ^= (1 << j);
        }
        int ans = 0;
        for (auto [i, mask] : rowToMask)
            ans += cnt[mask];
        ans += (n - (int) rowToMask.size()) * cnt[0];
        return ans;
    }
};