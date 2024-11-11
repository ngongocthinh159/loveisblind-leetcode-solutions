const int MX = 1000;
vector<bool> isPrime(MX + 1, true);
vector<int> primes;
auto init = [] {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MX; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= MX; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return 0;
}();
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int target = nums[i] - (prev + 1);
            auto it = upper_bound(primes.begin(), primes.end(), target);
            if (it != primes.begin()) {
                it--;
                x -= *it;
            }
            nums[i] = x;
            if (nums[i] <= prev) return false;
            prev = nums[i];
        }
        // for (auto x : nums) cout << x << " ";
        return true;
    }
};