class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n&1) return false; 
        int mn_open = 0, can_increase = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                if (mn_open >= 1) mn_open--, can_increase++;
                else mn_open++;
            } else {
                if (s[i] == '(') mn_open++;
                else mn_open--;
            }
            if (mn_open < 0) {
                if (can_increase == 0) return false;
                mn_open += 2;
                can_increase--;
            }
            if (i == n - 1 && mn_open != 0) return false;
        }
        return true;
    }
};  