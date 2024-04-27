class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        for (auto &trip : triplets) {
            if (trip[0] <= target[0] && trip[1] <= target[1] && trip[2] <= target[2]) {
                a = max(a, trip[0]);
                b = max(b, trip[1]);
                c = max(c, trip[2]);
            }
        }
        return a == target[0] && b == target[1] && c == target[2];
    }
};