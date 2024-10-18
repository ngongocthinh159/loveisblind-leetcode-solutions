class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        pair<int,int> mx = {INT_MIN, -1};
        int x = -1, y = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] - '0' < mx.first) {
                x = i; y = mx.second;
            }
            mx = (mx.first >= (s[i] - '0') ? mx : make_pair(s[i] - '0', i));
        }
        if (x != -1) swap(s[x], s[y]);
        return stoll(s);
    }
};