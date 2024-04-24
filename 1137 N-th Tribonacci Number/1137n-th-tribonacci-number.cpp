class Solution {
public:
    int tribonacci(int n) {
        vector<int> t(3);
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        if (n <= 2) return t[n];
        for (int i = 3; i <= n; i++) {
            int a = t[1];
            int b = t[2];
            t[2] = t[0] + t[1] + t[2];
            t[1] = b;
            t[0] = a;
        }
        return t[2];
    }
};