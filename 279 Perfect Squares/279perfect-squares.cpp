class Solution {
public:
    set<int> nums;
    int numSquares(int n) {
        for (int i = 1; i*i <= n; i++) {
            nums.insert(i*i);
        }
        deque<int> q;
        q.push_front(n);
        int level = 1;
        while (true) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.back(); q.pop_back();
                if (nums.count(cur)) {
                    return level;
                } else {
                    for (auto num : nums) {
                        if (num < cur) q.push_front(cur - num);
                        else break;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};