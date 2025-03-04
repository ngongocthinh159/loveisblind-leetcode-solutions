class Solution {
public:
    bool dfs(int n) {
        if (n == 0 || n == 2) return false;
        if (n == 1) return true;
        if (n%3 == 0) return dfs(n/3);
        if ((n - 1)%3 == 0) return dfs((n - 1)/3);
        return false;
    }
    bool checkPowersOfThree(int n) {
        return dfs(n);
    }
};