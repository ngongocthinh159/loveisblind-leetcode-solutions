#define ll long long
bool ok = false;
vector<bool> prime(1e6 + 1, true);
vector<int> spf(1e6 + 1);
void precal() {
    cout << "ok" << "\n";
    for (ll i = 2; i <= 1e6; i++) {
        if (prime[i]) {
            for (ll j = 2*i; j <= 1e6; j += i) {
                prime[i] = false;
            }
        }
        spf[i] = i;
    }
    spf[1] = 1;
    for (ll i = 2; i <= 1e6; i++) {
        if (spf[i] == i) {
            for (ll j = i*i; j <= 1e6; j += i) {
                spf[j] = min(spf[j], (int) i);
            }
        }
    }
}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (!ok) {
            ok = true;
            precal();
        }
        int ans = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                if (spf[nums[i]] == nums[i] || spf[nums[i]] > nums[i + 1]) return -1;
                nums[i] = spf[nums[i]];
                ans++;
            }
        }
        return ans;
    }
};