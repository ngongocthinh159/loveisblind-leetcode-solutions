class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int l = 0, r = 0, cost = 0;
        while (r < colors.size()) {
            char s = colors[r];
            int sum = neededTime[r]; int mx = neededTime[r];
            while (r + 1 < colors.size() && colors[r + 1] == s) {
                r++;
                sum += neededTime[r]; mx = max(mx, neededTime[r]);
            }

            if (r - l + 1 >= 2) {
                cost += sum - mx;
            }

            r++;
        }
        return cost;
    }
};