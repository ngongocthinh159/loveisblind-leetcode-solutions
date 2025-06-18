#define ll long long
struct MD {
    set<pair<int,int>> bot, top;
    ll sumbot = 0;
    ll sumtop = 0;
    int sz = 0;
    MD() {}

    void transferBotToTop() {
        auto itb = --bot.end();
        top.insert(*itb);
        sumtop += (*itb).first;
        sumbot -= (*itb).first;
        bot.erase(itb);
    }
    void insert(int val, int idx) {
        bot.insert({val, idx});
        sumbot += val;
        sz++;
        while (bot.size() && top.size() && (*(--bot.end())).first > (*top.begin()).first) {
            auto itb = --bot.end();
            auto itt = top.begin();
            auto valb = *itb;
            auto valt = *itt;
            bot.erase(itb);
            top.erase(itt);
            bot.insert(valt);
            top.insert(valb);
            sumbot += -valb.first + valt.first;
            sumtop += -valt.first + valb.first;
        }
        int szt = (sz + 1)/2;
        while (top.size() < szt) {
            transferBotToTop();
        }
    }

    void transferTopToBot() {
        auto itt = top.begin();
        bot.insert(*itt);
        sumbot += (*itt).first;
        sumtop -= (*itt).first;
        top.erase(itt);
    }
    void erase(int val, int pos) {
        sz--;
        if (bot.erase({val, pos})) {
            sumbot -= val;
        }
        if (top.erase({val, pos})) {
            sumtop -= val;
        }
        int szt = (sz + 1)/2;
        while (top.size() < szt) {
            transferBotToTop();
        }
        while (top.size() > szt) {
            transferTopToBot();
        }
    }
    ll sumToMed() {
        ll med = (*top.begin()).first;
        return med * ((int)bot.size()) - sumbot + sumtop - med * ((int)top.size());
    }
};
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const ll LINF = 1e18;
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LINF));
        vector<ll> cost(n);
        MD md;
        for (int i = 0; i < x; i++) {
            md.insert(nums[i], i);
        }
        cost[x - 1] = md.sumToMed();
        for (int i = x; i < n; i++) {
            md.insert(nums[i], i);
            md.erase(nums[i - x], i - x);
            cost[i] = md.sumToMed();
        }
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i - x >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - 1]);
            }
        }
        return dp[n][k];
    }
};