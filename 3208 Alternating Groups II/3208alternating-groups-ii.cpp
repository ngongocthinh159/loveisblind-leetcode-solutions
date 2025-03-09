class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), cnt = 0, l = 0;
        for (int r = 0; r - k + 1 <= n - 1; r++) {
            if (r > 0 && colors[r%n] == colors[(r - 1)%n]) {
                l = r;
            }
            if (r - l + 1 >= k) cnt++;
        }
        return cnt;
    }
};