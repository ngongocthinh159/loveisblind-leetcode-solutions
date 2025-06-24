class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int cnt = 0, n = nums.size();
        vector<int> v1, v2;
        for (int r = 0, l = 0; r < n; r++) {
            if (nums[r] == key) cnt++;
            while (r - l + 1 > k + 1) {
                if (nums[l++] == key) cnt--;
            }
            if (cnt) 
                v1.push_back(r);
        }
        cnt = 0;
        for (int r = n - 1, l = n - 1; r >= 0; r--) {
            if (nums[r] == key) cnt++;
            while (l - r + 1 > k + 1) {
                if (nums[l--] == key) cnt--;
            }
            if (cnt)
                v2.push_back(r);
        }
        reverse(v2.begin(), v2.end());
        vector<int> res(v1.size() + v2.size());
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};