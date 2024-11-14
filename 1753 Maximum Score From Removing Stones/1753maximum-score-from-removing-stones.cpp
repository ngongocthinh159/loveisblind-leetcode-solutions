class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int mx = max(a, max(b, c));
        int mn = min(a, min(b, c));
        int sc = a^b^c^mx^mn;
        if (mx >= mn + sc) return mn + sc;
        return (mx + mn + sc)/2;
    }
};