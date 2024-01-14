class Solution {
public:
    string mul(string &num1, char _x) {
        int x = _x - '0';
        string res = "";
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; i--) {
            int cur = (num1[i] - '0')*x;
            cur += carry;
            res += cur%10 + '0';
            carry = cur/10;
        }
        if (carry) res += carry + '0';
        return res;
    }
    void add(string &n1, string &n2, int start) {
        int carry = 0;
        int i = start;
        for (int j = 0; j < n2.size(); i++, j++) {
            int cur = (n1[i] - '0') + (j < n2.size() ? n2[j] - '0' : 0);
            cur += carry;
            n1[i] = cur%10 + '0';
            carry = cur/10;
        }
        if (carry) n1[i] = '1';
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.size() < num2.size()) return multiply(num2, num1);
        string _res(num1.size() + num2.size(), '0');
        for (int i = num2.size() - 1; i >= 0; i--) {
            string res = mul(num1, num2[i]);
            add(_res, res, (num2.size() - 1) - i);
        }
        while (_res.back() == '0') {
            _res.pop_back();
        }
        reverse(_res.begin(), _res.end());
        return _res;
    }
};