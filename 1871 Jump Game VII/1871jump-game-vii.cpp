class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        int curMaxIndex = 0;

        while (q.size() > 0) {
            int levelLength = q.size();

            for (int i = 0; i < levelLength; i++) {
                int curIndex = q.front();
                q.pop();

                int startIndex = max(curMaxIndex + 1, curIndex + minJump);
                int endIndex = min(curIndex + maxJump, (int) s.length() - 1);
                for (int j = startIndex; j <= endIndex; j++) {
                    if (s[j] == '0') {
                        q.push(j);
                        if (j == s.length() - 1) return true;
                    }
                    curMaxIndex = j;
                }
            }
        }

        return false;
    }
};