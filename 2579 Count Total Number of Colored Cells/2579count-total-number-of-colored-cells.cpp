class Solution {
public:
    long long coloredCells(int n) {
        return 4ll * (n + 2) * (n - 1) / 2 - 4*(n - 1) + 1;
    }
};