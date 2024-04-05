class Solution {
public:
    bool isBad(char c1, char c2) {
        return abs(c1 - c2) == abs('a' - 'A');
    }
    string makeGood(string s) {
        stack<char> S;
        for (auto c : s) {
            if (!S.size()) {
                S.push(c);
            } else {
                if (isBad(S.top(), c)) {
                    S.pop();
                } else {
                    S.push(c);
                }
            }
        }
        string res = "";
        while (S.size()) {
            res += S.top();
            S.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};