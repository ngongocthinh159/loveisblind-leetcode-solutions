class Solution {
public:
    string removeStars(string s) {
        stack<char> S;
        for (auto c : s) {
            if ('a' <= c && c <= 'z') S.push(c);
            else {
                S.pop();
            }
        }
        string res = "";
        while (S.size()) {
            res += S.top(); S.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};