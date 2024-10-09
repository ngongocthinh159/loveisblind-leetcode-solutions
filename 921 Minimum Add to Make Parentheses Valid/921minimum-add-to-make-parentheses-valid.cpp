class Solution {
public:
    int minAddToMakeValid(string s) {
        int preClose = 0;
        int surOpen = 0;
        for (auto c : s) {
            if (c == ')') {
                if (surOpen > 0) surOpen--;
                else preClose++;
            } else {
                surOpen++;
            }
        }
        return preClose + surOpen;
    }
};