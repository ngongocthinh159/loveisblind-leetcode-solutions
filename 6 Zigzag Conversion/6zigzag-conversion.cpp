class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> v(numRows);
        bool isIncrease = true;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            v[cnt] += s[i];
            if (isIncrease) {
                cnt++;
                if (cnt == numRows - 1) { isIncrease = false;}
            } else {
                cnt--;
                if (cnt == 0) {isIncrease = true;}
            }
        }

        string res = "";
        for (int i = 0; i < v.size(); i++) {
            res += v[i];
        }
        return res;
    }
};