#define N 1000005
int spf[N];
int buf[25];
auto init = []{
    for (int i = 0; i < N; i++) spf[i] = i;
    spf[0] = spf[1] = -1;
    for (int i = 2; i * i < N; i++) if (i == spf[i])
        for (int j = i * i; j < N; j += i) spf[j] = min(spf[j], i);
    return 0;
}();
class Solution {
public:
    int top;
    void factorize(int x) {
        top = 0;
        while (x != 1) {
            int fact = spf[x];
            while (x % fact == 0) x /= fact;
            buf[top++] = fact;
        }
    }
    bool isPrime(int x) {
        return spf[x] == x;
    }
    int minJumps(vector<int>& nums) {
        unordered_map<int,vector<int>> pToIdx;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            factorize(nums[i]);
            for (int j = 0; j < top; j++)
                pToIdx[buf[j]].push_back(i);
        }
        vector<bool> vis(n);
        vis[0] = 1;
        deque<int> q;
        q.push_front(0);
        int level = 0;
        while (q.size()) {
            for (int sz = q.size(); sz; sz--) {
                int i = q.back();
                if (i == n - 1) 
                    return level;
                q.pop_back();
                if (i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push_front(i + 1);
                }
                if (i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push_front(i - 1);
                }
                if (isPrime(nums[i])) {
                    for (auto idx : pToIdx[nums[i]]) {
                        if (!vis[idx]) {
                            vis[idx] = 1;
                            q.push_front(idx);
                        }
                    }
                    pToIdx[nums[i]].clear();
                }
            }
            level++;
        }
        return -1;
    }
};