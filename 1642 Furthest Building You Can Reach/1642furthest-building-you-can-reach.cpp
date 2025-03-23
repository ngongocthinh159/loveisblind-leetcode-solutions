class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        int n = heights.size();
        for (int i = 1; i < n; i++) {
            int dif = heights[i] - heights[i - 1];
            if (dif <= 0) continue;
            bricks -= dif;
            q.push(dif);
            if (bricks < 0) {
                bricks += q.top();
                q.pop();
                ladders--;
            }
            if (ladders < 0)
                return i - 1;
        }
        return n - 1;
    }
};