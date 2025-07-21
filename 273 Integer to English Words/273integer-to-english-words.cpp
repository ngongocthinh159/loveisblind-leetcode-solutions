class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> tens2 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string convertTen(string &s) {
        int n = s.size();
        string res = "";
        if (n == 2 && s[0] != '0') {
            if (s[0] == '1') {
                res += tens2[s[1] - '0'];
            } else {
                res += tens[s[0] - '0'];
                if (ones[s[1] - '0'].size())
                    res += " " + ones[s[1] - '0'];
            }
        } else {
            res += ones[s[0] - '0'];
        }
        return res;
    }
    string convertHundred(string s) {
        if (s == "0") return "Zero";
        int n = s.size();
        if (n == 1) return ones[s[0] - '0'];
        string res = "";
        if (n == 3) {
            res += ones[s[0] - '0'] + " Hundred";
            s = s.substr(1);
        }
        string tmp = convertTen(s);
        if (tmp.size()) {
            if (res.size())
                res += ' ';
            res += tmp;
        }
        return res;
    }
    string numberToWords(int num) {
        vector<string> v;
        vector<string> surf = {"", "Thousand", "Million", "Billion"};
        string s = to_string(num);
        int n = s.size();
        for (int i = n - 1; i >= 0; i -= 3) {
            int st = max(0, i - 2);
            int e = i;
            v.push_back(s.substr(st, e - st + 1));
        }
        reverse(v.begin(), v.end());
        string res = "";
        for (int i = 0; i < (int) v.size(); i++) {
            if (res.size()) res += " ";
            res += convertHundred(v[i]);
            if (surf[(int) v.size() - i - 1].size())
                res += " " + surf[(int) v.size() - i - 1];
        }
        return res;
    }
};