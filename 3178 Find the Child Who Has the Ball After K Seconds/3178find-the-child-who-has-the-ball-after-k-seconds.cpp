class Solution {
public:
    int numberOfChild(int n, int k) {
        int dir = k / (n - 1);
        int startIdx = dir % 2 == 0 ? 0 : n - 1;
        int remain = k % (n - 1);
        int ans;
        if (startIdx == 0) ans = startIdx + remain;
        else ans = startIdx - remain;
        return ans;
    }
};