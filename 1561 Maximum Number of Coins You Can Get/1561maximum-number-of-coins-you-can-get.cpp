class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res = 0;
        for (int i = piles.size() - 1; i >= piles.size() / 3 + 1; i-=2) {
            res += piles[i - 1];
        }
        return res;
    }
};