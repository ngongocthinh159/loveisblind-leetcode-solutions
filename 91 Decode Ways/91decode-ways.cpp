class Solution {
public:
    int numDecodings(string s) {
        int cur, next = 1, nextNext = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') 
                cur = 0;
            else if (s[i] == '1' || 
                (s[i] == '2' && i + 1 < s.size() && s[i + 1] <= '6'))
                cur = next + nextNext;
            else
                cur = next;
            nextNext = next; next = cur;
        } 
        return cur;
    }
};