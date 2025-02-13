class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for (auto x : nums) if (x < k) q.push(x);
        int cnt = 0;
        while (q.size() > 1) {
            cnt++;
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            if (1LL*2*a + b < k) q.push(2*a + b);
        }
        return cnt + q.size();
    }
};