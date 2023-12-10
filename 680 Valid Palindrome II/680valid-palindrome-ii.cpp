class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {i++; j--;}
            else if (s[i] != s[j]) {
                return isPalind(s, i + 1, j) || isPalind(s, i, j - 1);
            }
        }
        return true;
    } 

    bool isPalind(string& s, int i, int j) {
        while (i < j && s[i] == s[j]) {
            i++; j--;
        }
        return i >= j;
    }
};