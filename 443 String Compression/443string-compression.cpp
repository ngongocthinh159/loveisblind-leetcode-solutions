class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        while (i < chars.size()) {
            char start = chars[i];
            int sI = i;
            while (i + 1 < chars.size() && chars[i + 1] == start) {
                i++;
            }
            chars[j++] = start;
            if ((i - sI + 1) > 1) {
                string ss = to_string(i - sI + 1);
                for (int k = 0; k < ss.size(); k++) {
                    chars[j++] = ss[k];
                }
            }

            i++;
        }
        return j;
    }
};