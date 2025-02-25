const int mod = 1e9 + 7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), freq[2], parity = 0, ans = 0;
        freq[0] = 1, freq[1] = 0;
        for (int i = 0; i < n; i++) {
            parity ^= (arr[i]&1);
            ans = (ans + freq[parity^1])%mod;
            freq[parity]++;
        }
        return ans;
    }
};