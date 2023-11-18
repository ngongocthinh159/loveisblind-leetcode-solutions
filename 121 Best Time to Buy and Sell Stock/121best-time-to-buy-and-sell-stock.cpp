class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int maxTilNow = prices[prices.size() - 1];
        int res = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            res = max(res, maxTilNow - prices[i]);
            maxTilNow = max(maxTilNow, prices[i]);
        }
        return res;
    }
};