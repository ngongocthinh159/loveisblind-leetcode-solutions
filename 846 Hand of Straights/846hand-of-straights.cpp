class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>cnt;
        for (auto x : hand) {
            cnt[x]++;
        }
        for (auto x : hand) {
            int cur = x;
            while (cnt[x - 1]) {
                x--;
            }

            while (x <= cur) {
                while (cnt[x]) {
                    for (int i = x; i <= x + groupSize - 1; i++) {
                        if (!cnt[i]) return false;
                        else cnt[i]--;
                    }
                }
                x++;
            }
        }
        return true;
    }
};