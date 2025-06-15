class Solution {
public:
    int toMax(int num) {
        string s = to_string(num);
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '9') {
                char c = s[i];
                while (i < n) {
                    if (s[i] == c) s[i] = '9';
                    i++;
                }
                break;
            }
        }
        for (int i = 0; i < n; i++) res = 10 * res + (s[i] - '0');
        return res;
    }
    int toMin(int num) {
        string s = to_string(num);
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if ((i == 0 && s[i] != '1') || (i != 0 && s[i] != '0' && s[i] != '1')) {
                char c = s[i];
                int pick = i == 0 ? 1 : 0;
                while (i < n) {
                    if (s[i] == c) s[i] = pick + '0';
                    i++; 
                }
                break;
            }
        }
        for (int i = 0; i < n; i++) res = 10 * res + (s[i] - '0');
        return res;
    }
    int maxDiff(int num) {
        // cout << toMax(num) << ' ' << toMin(num) << '\n';
        return toMax(num) - toMin(num);
    }
};