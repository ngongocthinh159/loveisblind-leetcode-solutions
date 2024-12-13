class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        for (auto x : gifts) q.push(x);
        for (int i = 0; i < k; i++) {
            auto x = q.top(); q.pop();
            if (x == 1) {
                q.push(x);
                break;
            }
            q.push(sqrt(x));
        }
        long long ans = 0;
        while (q.size()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};