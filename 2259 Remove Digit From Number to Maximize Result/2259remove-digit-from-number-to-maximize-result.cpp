class Solution {
public:
    string removeDigit(string number, char digit) {
        int last_idx = -1;
        int n = number.size();
        for (int i = 0; i < n;) {
            char c = number[i];
            if (c == digit) {
                while (i < n && number[i] == c) {
                    last_idx = i;
                    i++;
                }
                if (i < n && number[i] > c) {
                    break;
                }
            } else
                i++;
        }
        string res = "";
        for (int i = 0; i < n; i++) if (i != last_idx) res += number[i];
        return res;
    }
};