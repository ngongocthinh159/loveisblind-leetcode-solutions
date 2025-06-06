class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char,int> cToVal = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int n = s.size(), i = 0;
        while (i < n) {
            if (i + 1 < n && cToVal[s[i + 1]] > cToVal[s[i]]) {
                res += cToVal[s[i + 1]] - cToVal[s[i]];
                i++;
            } else {
                res += cToVal[s[i]];
            }
            i++;
        }
        return res;
    }
};