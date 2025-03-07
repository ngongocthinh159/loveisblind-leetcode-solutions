#define MAXN 1000005
bool prime[MAXN];
auto init = [] {
    for (int i = 2; i < MAXN; i++) prime[i] = true;
    for (int i = 2; i*i < MAXN; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAXN; j += i)
                prime[j] = false;
        }
    }
    return 0;
}();
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int last = -1;
        int dist = INT_MAX;
        vector<int> res = {-1, -1};
        for (int j = left; j <= right; j++) {
            if (prime[j]) {
                if (last != -1 && dist > j - last) {
                    dist = j - last;
                    res[0] = last, res[1] = j;
                }
                last = j;
            }
        }
        return res;
    }
};