class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int sum = 0, unique = 0, ans = 0;
        vector<int> f(n);
        for (int r = 0, l = 0; r < n; r++) {
            if (++f[fruits[r]] == 1) unique++;
            sum += fruits[r];
            while (l <= r && unique > 2) {
                if (--f[fruits[l]] == 0) sum -= fruits[l], unique--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};