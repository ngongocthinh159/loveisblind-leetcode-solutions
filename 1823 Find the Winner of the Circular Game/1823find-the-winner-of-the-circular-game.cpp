class Solution {
public:
    int findTheWinner(int n, int k) {
        return dfs(n, k) - 1;
    }
    int dfs(int n, int k) {
        if (n == 1) return 1;
        return (dfs(n - 1, k) + k) % n;
    }
};