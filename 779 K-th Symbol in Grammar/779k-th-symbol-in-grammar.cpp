class Solution {
public:
    int dfs(int n, int k) {
        if (n == 0) return 0;
        return dfs(n - 1, (k + 1)/2) ^ (k % 2 == 0 ? 1 : 0);
    }
    int kthGrammar(int n, int k) {
        return dfs(n - 1, k);
    }
};