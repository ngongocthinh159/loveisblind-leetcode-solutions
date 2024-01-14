class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) return addBinary(b, a);
        int carry = 0;
        string res = "";
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0; i--, j--) {
            int cur = (a[i] - '0') + (j >= 0 ? (b[j] - '0') : 0);
            cur += carry;
            res += (char) (cur%2 + '0');
            carry = cur/2;
        }
        if (carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};