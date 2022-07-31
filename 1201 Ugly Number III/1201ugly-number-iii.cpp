class Solution {
public:
    long long lcm2(long long a, long long b) {
        return (long long) a * b / gcd(a,b);
    }
    
    bool haveAtLeastNUrglyNumber(long long mid, int n, int a, int b, int c) {
        // To calculate how many number are divisible by a, b or c in rang 1 => n
        // We use this formular
        int cnt = mid/a + mid/b + mid/c - mid/lcm2(a,b) - mid/lcm2(b,c) - mid/lcm2(a,c) + mid/lcm2(a,lcm2(b,c));
        
        // Formular explanation
        // https://leetcode.com/problems/ugly-number-iii/discuss/387539/cpp-Binary-Search-with-picture-and-Binary-Search-Template
        return cnt >= n;
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        int l = 1, r = 2 * 1E9;
        
        while (l < r) {
            long long m = l + ((r - l) >> 1);
            
            if (haveAtLeastNUrglyNumber(m, n, a, b, c)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        return r;
    }
};