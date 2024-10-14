class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        long long score = 0;
        for (int i = 0; i < k; i++) {
            int top = pq.top(); pq.pop();
            score += top;
            pq.push(ceil((double) top/3));
        }
        return score;
    }
};