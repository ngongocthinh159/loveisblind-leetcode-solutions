class Solution {
public:
    int numSteps(string s) {
        int one_cnt = 0;
        int zero_cnt = 1;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') one_cnt++;
            else if (s[i] == '0' && one_cnt != 0) zero_cnt++;
        }
        return one_cnt == 1 ? n - 1 : zero_cnt + n;
    }
};