class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int i = 0, cnt = 0;
        while (i < n) {
            int s = i, e = i;
            char c = word[i];
            while (i < n && c == word[i]) e = i, i++;
            if (e - s + 1 > 1) cnt += (e - s + 1) - 1;
        }
        return 1 + cnt;
    }
};