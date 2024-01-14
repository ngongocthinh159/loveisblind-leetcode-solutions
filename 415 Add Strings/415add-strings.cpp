class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) return addStrings(num2, num1);
        string res = "";
        int carry = 0;
        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0; i--, j--) {
            int cur = (num1[i] - '0') + (j >= 0 ? (num2[j] - '0') : 0);
            cur += carry;
            res += (char) (cur%10 + '0');
            carry = cur/10;
        }
        if (carry) res += (char) (carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};