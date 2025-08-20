class Solution {
public:
    string largestGoodInteger(string num) {
        char digit = ' ';
        string res = "";
        int l = 0, r = 1;
        char start = num[0];
        int cnt = 1;
        while (r < num.size()) {
            char c = num[r];
            if (c == start) cnt++;

            // revalidate window
            if (c != start) {
                l = r; cnt = 1; start = c;
            } else if (c == start && cnt > 3) {
                cnt--;
                l++;
            }

            if (cnt == 3 && digit < start) {
                digit = start;
                res = "";
                res += start;
                res += start;
                res += start;
            }

            r++;
        }
        return res;
    }
};