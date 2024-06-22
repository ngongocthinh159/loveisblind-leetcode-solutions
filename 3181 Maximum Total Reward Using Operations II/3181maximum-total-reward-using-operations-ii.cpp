class Solution {
public:
    
    int maxTotalReward(vector<int>& a) {
        const int LEN = 2*5e4 + 5;
        int n = a.size();
        bitset<LEN> sum_ok;
        sum_ok.set(0);
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            bitset<LEN> cur = sum_ok;
            cur <<= (LEN - a[i]);
            cur >>= (LEN - a[i]);
            cur <<= a[i];
            sum_ok |= cur;
        }
        int ans = -1;
        for (int i = LEN - 1; i >= 0; i--) {
            if (sum_ok.test(i)) {ans = i; break;}
        }
        return ans;
    }
};