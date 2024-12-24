#define ll long long
class Solution {
public:
    int arrangeCoins(int n) {
        ll a = 1, b = 1, c = -2LL*n;
        double sqrt_delta = sqrt(b*b - 4*a*c);
        double x1 = (-b + sqrt_delta)/(2 * a);
        return x1;
    }
};