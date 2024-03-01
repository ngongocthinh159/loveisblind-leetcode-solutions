class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0, cnt0 = 0;
        for (auto c : s) {
            if (c=='0')cnt0++;
            else cnt1++;
        }
        string res = "";
        for (int i = 0; i < cnt1-1; i++) {
            res +='1';
        }
        for (int i = 0;i < cnt0; i++) {
            res+='0';
        }
        if (cnt1>= 1)res+='1';
        return res;
    } 
};