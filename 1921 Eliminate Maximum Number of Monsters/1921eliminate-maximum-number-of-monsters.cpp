class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> steps(n);
        for (int i = 0; i < n; i++) {
            steps[i] = (dist[i] + speed[i] - 1)/speed[i];
        }
        sort(steps.begin(), steps.end());
        for (int i = 0; i < n; i++) {
            if (steps[i] < i + 1) {
                return i;
            }
        }
        return n;
    }
};