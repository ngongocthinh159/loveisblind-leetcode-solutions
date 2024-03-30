class Solution {
public:
    int myAtoi(string s) {
        string mx = "2147483647";
        string mn = "2147483648";

        char sign = '+';
        int i = 0;
        int ans = 0;
        int n = s.size();
        string cur = "";
        while (i < n) {
            if (s[i] == ' ') {i++; continue;}
            if (!('0' <= s[i] && s[i] <= '9') && s[i] != '+' && s[i] != '-') {
                break;
            }

            if (s[i] == '+' || s[i] == '-') {
                if (s[i] == '-') sign = '-';
                i++;
            }

            bool ok = false;
            while (i < n && '0' <= s[i] && s[i] <= '9') {
                if (!ok && s[i] == '0') {i++; continue;}
                if (s[i] != '0') {ok = true;}
                cur += s[i];
                i++;
            }

            break;
        }

        if (sign == '+' && (cur == mx || cur.size() > mx.size() || (cur.size() == mx.size() && cur > mx))) {
            return INT_MAX;
        } else if (sign == '-' && (cur == mn || cur.size() > mn.size() || (cur.size() == mn.size() && cur > mn))) {
            return INT_MIN;
        }

        if (cur != "") {
            for (int i = 0; i < cur.size(); i++) {
                ans = ans*10 + ((int) (cur[i] - '0')); 
            }
        }

        if (sign == '-') ans *= -1;
        return ans;
    }
};