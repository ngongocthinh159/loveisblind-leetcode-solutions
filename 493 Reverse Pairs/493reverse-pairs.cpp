class Solution {
public:
    int ans = 0;
    int reversePairs(vector<int>& nums) {
        merge_sort(nums, 0, (int) nums.size() - 1);
        return ans;
    }
    void merge_sort(vector<int> &nums, int l, int r) {
        if (l == r) return;
        int m = (l + r)/2;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            while (i <= m && !(nums[i] > 2LL * nums[j])) i++;
            if (i <= m) ans += (m - i + 1);
            j++;
        }
        i = l, j = m + 1;
        int k = 0;
        vector<int> res(r - l + 1);
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) res[k++] = nums[i++];
            else res[k++] = nums[j++];
        }
        while (i <= m) res[k++] = nums[i++];
        while (j <= r) res[k++] = nums[j++];
        i = l, k = 0;
        while (i <= r) nums[i++] = res[k++];
    }
};