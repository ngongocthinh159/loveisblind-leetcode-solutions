class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(s.size() + 1);
        for (auto &sh : shifts) {
            if (sh[2] == 1) {
                diff[sh[0]]++;
                diff[sh[1] + 1]--;
            } else {
                diff[sh[0]]--;
                diff[sh[1] + 1]++;
            }
        }
        for (int i = 1; i < diff.size(); i++) diff[i] += diff[i - 1];
        string res = "";
        for (int i = 0; i < n; i++) res += (((s[i] - 'a') + diff[i])%26 + 26) % 26 + 'a';
        return res;
    }
};