class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        queue<int> q;
        q.push(0);
        int curMaxIndex = 0, curLevel = 1;

        while (q.size() > 0) {
            int levelLength = q.size();

            for (int i = 0; i < levelLength; i++) {
                int curIndex = q.front();
                q.pop();

                int startIndex = curMaxIndex + 1;
                for (int j = startIndex; j <= curIndex + nums[curIndex]; j++) {
                    q.push(j);
                    curMaxIndex = j;
                    if (j == nums.size() - 1) {
                        return curLevel;
                    }
                }
            }

            curLevel++;
        }

        return -1;
    }
};