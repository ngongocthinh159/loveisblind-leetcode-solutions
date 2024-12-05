class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int m = target.size();
        int i = 0, j = 0;
        while (j < m) {
            while (j < m && target[j] == '_') j++;
            if (j < m) {
                char c = target[j];
                while (i < n && start[i] == '_') i++;
                if (i < n) {
                    if (start[i] == c) {
                        if (c == 'L') {
                            if (!(i >= j)) return false;
                        } else {
                            if (!(i <= j)) return false;
                        }
                    } else return false;
                    i++;
                } else return false;
                j++;
            }
        }
        while (i < n && start[i] == '_') i++;
        return i == n;
    }
};