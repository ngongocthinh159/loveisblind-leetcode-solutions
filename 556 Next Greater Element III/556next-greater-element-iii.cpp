class Solution {
public:
    int nextGreaterElement(int n) {
        int x = n;
        multiset<int> S;
        int mx = -1;
        while (x > 0) {
            int digit = x%10;
            if (mx > digit) {
                auto it = S.upper_bound(digit);
                int replace = *it;
                x -= digit;
                x += replace;
                S.insert(digit);
                S.erase(it);
                for (auto d : S) {
                    if (!(x <= INT_MAX/10)) return -1;
                    x *= 10;
                    if (!(x <= INT_MAX - d)) return -1;
                    x += d;
                }
                break;
            }
            mx = max(mx, digit);
            S.insert(digit);
            x /= 10;
        }
        return x == 0 ? -1 : x;
    }
};