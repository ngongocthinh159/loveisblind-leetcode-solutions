class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for (auto log : logs) {
            int dots = 0;
            for (int i = 0; i < log.size(); i++) {
                if (log[i] == '.') dots++;
            }
            if (dots == 2) {
                level = max(level - 1, 0);
            } else if (dots == 0) {
                level++;
            }
        }
        return level;
    }
};