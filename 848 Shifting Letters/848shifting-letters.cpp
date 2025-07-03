class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long acc = 0;
        for (int i = n - 1; i >= 0; i--) {
            acc += shifts[i];
            s[i] = (s[i] - 'a' + acc) % 26 + 'a';
        }
        return s;
    }
};