class Solution {
public:
    void exchange(set<pair<int,int>> &bot, set<pair<int,int>> &top) {
        if (bot.size() && top.size() && (*top.begin()).first < (*(--bot.end())).first) {
            auto it1 = bot.end();
            it1--;
            auto it2 = top.begin();
            auto val1 = *it1;
            auto val2 = *it2;
            bot.erase(it1);
            bot.insert(val2);
            top.erase(it2);
            top.insert(val1);
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int sz = (k + 1)/2, n = nums.size();
        set<pair<int,int>> bot, top;
        vector<double> res(n - k + 1);
        for (int i = 0; i < n; i++) {
            bot.insert({nums[i], i});
            if (i >= k - 1) {
                if (i - k >= 0) {
                    bot.erase({nums[i - k], i - k});
                    top.erase({nums[i - k], i - k});
                }
                exchange(bot, top);
                while (top.size() != sz) {
                    if (top.size() < sz) {
                        auto it = bot.end();
                        it--;
                        top.insert(*it);
                        bot.erase(it);
                    } else {
                        auto it = top.begin();
                        bot.insert(*it);
                        top.erase(it);
                    }
                }

                res[i - k + 1] = (k & 1) ? (*top.begin()).first : 
                    (1.00 * (*top.begin()).first / 2 + 1.00 * (*(--bot.end())).first / 2);
            }
        }
        return res;
    }
};