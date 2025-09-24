class Solution {
public:
    string fractionToDecimal(int num, int de) {
        long long numerator = abs(1LL * num);
        long long denominator = abs(1LL * de);
        string sign = "";
        if (1LL * num * de < 0) sign = "-";
        string ans = "";
        if (numerator >= denominator) {
            long long q = numerator / denominator;
            ans += to_string(q);
            numerator -= q * denominator;
        }
        else
            ans += '0';
        if (numerator == 0) return sign + ans;
        ans += '.';
        string s = "";
        unordered_map<long long,int> seen;
        while (numerator != 0) {
            if (seen.count(numerator)) {
                int sz = s.size();
                s += 'a';
                int idx = seen[numerator];
                for (int j = sz - 1; j >= idx; j--) s[j + 1] = s[j];
                s[idx] = '(';
                s += ')';
                break;
            }
            seen[numerator] = s.size();
            int cnt = 0;
            while (numerator < denominator) {
                numerator *= 10;
                cnt++;
            }
            for (int j = 1; j < cnt; j++) s += '0';
            s += numerator/denominator + '0';
            numerator = numerator % denominator;
        }

        ans += s;
        ans = sign + ans;
        return ans;
    }
};