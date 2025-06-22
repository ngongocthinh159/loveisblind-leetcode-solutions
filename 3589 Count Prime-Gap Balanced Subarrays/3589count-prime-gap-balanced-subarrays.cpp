#define N 100005
bitset<N> prime;
auto init = []{
    prime.flip();
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i < N; i++) if (prime[i])
        for (int j = i * i; j < N; j += i) prime[j] = 0;
    return 0;
}();
class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        multiset<int> p;
        bool foundl = false;
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            if (prime[nums[i]]) {
                p.insert(nums[i]);
                cnt++;
            }

            while (l <= i && cnt >= 2) {
                foundl = true;
                if (prime[nums[l++]]) cnt--;
            }

            while (r <= i && (int) p.size() >= 2 && (*p.rbegin() - *p.begin() > k)) {
                if (prime[nums[r]]) {
                    p.erase(p.find(nums[r]));
                }
                r++;
            }
            
            // cout << i << ' ' << l << ' ' << r << '\n';
            if (foundl) {
                if (r <= l - 1) {
                    ans += l - 1 - r + 1;
                }
            }
        }
        return ans;
    }
};