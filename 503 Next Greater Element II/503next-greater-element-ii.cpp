class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ng(2*n);
        deque<int> q;
        for (int i = 0; i < n; i++) nums.push_back(nums[i]);
        for (int i = 2*n - 1; i >= 0; i--) {
            while (q.size() && nums[i] >= nums[q.front()]) q.pop_front();
            if (q.size()) ng[i] = nums[q.front()%n];
            else ng[i] = -1;
            q.push_front(i);
        }
        return vector<int>(ng.begin(), ng.begin() + n);
    }
};