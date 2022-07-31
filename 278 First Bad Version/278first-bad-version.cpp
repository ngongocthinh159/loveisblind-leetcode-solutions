// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        
        while (l < r) {
            int m = l + ((r - l) >> 1);
            
            if (!isBadVersion(m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        return l;
    }
};