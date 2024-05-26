class Solution {
public:
    long long m;
    bool check(int x, vector<int>& nums) {
        long long cnt = 0;
        int l = 0, r = 0;
        unordered_map<int,int> M;
        int lastL = -1;
        while (r < nums.size()) {
            int &cnt1 = M[nums[r]];
            cnt1++;

            while (l <= r && M.size() > x) {
                int &cnt2 = M[nums[l]];
                cnt2--;
                if (cnt2 == 0) M.erase(nums[l]);

                l++;
            }

            cnt += 1LL*(r - l + 1);

            r++;
        }
        // cout << "x: " << x << ", cnt sub <= x: " << cnt << "\n";
        return cnt >= m;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        long long subarrays = 1LL*n*(n+1)/2;
        m = 1LL*(subarrays + 1)/2;
        // cout << subarrays << "\n";
        // cout << m << "\n";
        unordered_set<int> S;
        for (auto &x : nums) {
            S.insert(x);
        }
        int l = 0, r = (int) S.size() + 1;
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            if (check(mid, nums)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};