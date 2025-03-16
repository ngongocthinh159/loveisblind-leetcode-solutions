#define ll long long
class Solution {
public:
    bool check(ll x, vector<int>& ranks, int cars) {
        ll tot = 0;
        for (auto r : ranks) {
            tot += sqrt(x/r);
        }
        return tot >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 0, r = 1e18;
        while (r - l > 1) {
            ll m = l + (r - l)/2;
            if (check(m, ranks, cars))
                r = m;
            else
                l = m;
        }
        return r;
    }
};