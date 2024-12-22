class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        deque<int> q;
        for (int i = n - 1; i >= 0; i--) {
            while (q.size() && heights[i] > heights[q.front()]) {
                ans[i]++;
                q.pop_front();
            }
            if (q.size()) ans[i]++;
            q.push_front(i);
        }
        return ans;
    }
};