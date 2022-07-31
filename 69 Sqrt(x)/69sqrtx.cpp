class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            
            if ((long long) m * m >= x) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        if ((long long) r*r == x) return r;
        else return r - 1;
}
};