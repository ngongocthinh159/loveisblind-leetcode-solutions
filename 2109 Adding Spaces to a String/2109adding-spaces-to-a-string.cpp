class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int j = 0;
        int m = spaces.size();
        for (int i = 0; i < s.size(); i++) {
            if (j < m && spaces[j] == i) {
                res += ' ';
                j++;
            }
            res += s[i];
        }
        return res;
    }
};