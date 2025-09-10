class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int n1 = 0, n2 = 0;
        string s = to_string(n);
        int k = s.size();
        int carry = 0;
        for (int i = k - 1, mul = 1; i >= 0; i--, mul *= 10) {
            int d = (s[i] - '0' + carry);
            if (d < 0)  {
                d += 10;
                carry = -1;
            } else
                carry = 0;
            if (d <= 1) {
                if (i == 0) {
                    if (d == 1) n1 += d * mul;
                } else {
                    if (d == 0) n1 += 5 * mul, n2 += 5 * mul;
                    else if (d == 1) n1 += 6 * mul, n2 += 5 * mul;
                    carry = -1;
                }
            } else {
                n1 += mul * ((d + 1)/2);
                n2 += mul * (d / 2);
            }
            // cout << n1 << ' ' << n2 << '\n';
        }
        return {n1, n2};
    }
};