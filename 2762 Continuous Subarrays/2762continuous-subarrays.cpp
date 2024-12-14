class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int l = 0, cur_mn, cur_mx, len;
        int n = nums.size();
        deque<int> mnq;
        deque<int> mxq;
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            while (mnq.size() && nums[mnq.back()] >= nums[r]) mnq.pop_back();
            mnq.push_back(r);
            while (mxq.size() && nums[mxq.front()] <= nums[r]) mxq.pop_front();
            mxq.push_front(r);

            while (mnq.size() && !(l <= mnq.front() && mnq.front() <= r)) mnq.pop_front();
            while (mxq.size() && !(l <= mxq.back() && mxq.back() <= r)) mxq.pop_back();
            cur_mn = nums[mnq.front()];
            cur_mx = nums[mxq.back()];
            while (l <= r && cur_mx - cur_mn > 2) {
                l++;
                while (mnq.size() && !(l <= mnq.front() && mnq.front() <= r)) mnq.pop_front();
                while (mxq.size() && !(l <= mxq.back() && mxq.back() <= r)) mxq.pop_back();
                cur_mn = nums[mnq.front()];
                cur_mx = nums[mxq.back()];
            }
            
            ans += (r - l + 1);
        }
        return ans;
    }
};