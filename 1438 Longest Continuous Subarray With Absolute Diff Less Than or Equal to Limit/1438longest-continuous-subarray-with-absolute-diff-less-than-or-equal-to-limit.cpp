class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, r = 0, cur_max, cur_min, n = nums.size(), ans = INT_MIN;
        deque<pair<int, int>> minq, maxq;
        while (r < n) {
            while (minq.size() && nums[r] <= minq.back().first) minq.pop_back();
            minq.push_back({nums[r], r});
            while (maxq.size() && nums[r] >= maxq.front().first) maxq.pop_front();
            maxq.push_front({nums[r], r});

            while (minq.size() && !(l <= minq.front().second && minq.front().second <= r)) minq.pop_front();
            cur_min = minq.front().first;
            while (maxq.size() && !(l <= maxq.back().second && maxq.back().second <= r)) maxq.pop_back();
            cur_max = maxq.back().first;
            while (l <= r && (cur_max - cur_min > limit)) {
                l++;
                while (minq.size() && !(l <= minq.front().second && minq.front().second <= r)) minq.pop_front();
                cur_min = minq.front().first;
                while (maxq.size() && !(l <= maxq.back().second && maxq.back().second <= r)) maxq.pop_back();
                cur_max = maxq.back().first;
            }

            ans = max(ans, r - l + 1);

            r++;
        }
        return ans;
    }
};