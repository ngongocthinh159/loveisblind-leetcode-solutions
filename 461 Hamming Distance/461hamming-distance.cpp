class Solution {
public:
    int countBits(int x) {
        int cnt = 0;
        while (x != 0) {
            cnt++;
            x = x&(x-1);
        }
        return cnt;
    }
    int hammingDistance(int x, int y) {
        return countBits(x^y);
    }
};