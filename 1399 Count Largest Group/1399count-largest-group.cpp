class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> freq;
        for (int i = 1; i <= n; i++) {
            int sum = 0, x = i;
            while (x) sum += x % 10, x /= 10;
            freq[sum]++;
        }
        int mx = 0, res = 0;
        for (auto [sum, cnt] : freq) {
            if (mx < cnt) {
                mx = cnt;
                res = 1;
            } else if (mx == cnt)
                res++;
        }
        return res;
    }
};