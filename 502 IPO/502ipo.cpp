class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        for (int i = 0; i < capital.size(); i++) v.push_back({capital[i], profits[i]});
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int cur = w, r = 0;
        for (int i = 0; i < k; i++) {
            for (; v[r].first <= cur && r < capital.size(); r++) {
                pq.push(v[r].second);
            }
            if (!pq.size()) break;
            cur += pq.top();
            pq.pop();
        }
        return cur;
    }
};