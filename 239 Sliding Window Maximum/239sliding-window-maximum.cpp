class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int r = 0; r < k; r++) {
            while (dq.size() && nums[dq.back()] <= nums[r]) dq.pop_back();
            dq.push_back(r);
        }
        ans.push_back(nums[dq.front()]);
        for (int r = k; r < nums.size(); r++) {
            while (dq.size() && nums[dq.back()] <= nums[r]) dq.pop_back();
            dq.push_back(r);
            if (dq.front() == r - k) dq.pop_front();
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};