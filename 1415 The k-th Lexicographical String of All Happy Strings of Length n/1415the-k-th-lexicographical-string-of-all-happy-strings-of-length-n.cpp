class Solution {
public:
    string getHappyString(int n, int k) {
        int last = 4;
        string res = "";
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = 0; j < 3; j++) if (j != last) {
                if (k <= pow(2, n - (i + 1))) {
                    res += 'a' + j;
                    last = j;
                    ok = true;
                    break;
                } 
                else {
                    k -= pow(2, n - (i + 1));
                }
            }
            if (!ok) break;
        }
        return res;
    }
};