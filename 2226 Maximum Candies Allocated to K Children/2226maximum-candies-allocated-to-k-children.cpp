class Solution {
public:
    bool check(int x, vector<int> &candies, long long k) {
        long long cur = 0;
        for (auto c : candies) cur += c / x;
        return cur >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = *max_element(candies.begin(), candies.end()) + 1;
        while (r - l > 1) {
            int m = (l + r)/2;
            if (check(m, candies, k))
                l = m;
            else
                r = m;
        }
        return l;
    }
};