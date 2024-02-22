class Solution {
public:
    int findJudge(int n, vector<vector<int>>& _trust) {
        unordered_map<int,int> trust;
        unordered_map<int,int> be_trusted;
        for (auto &v : _trust) {
            int a = v[0];
            int b = v[1];
            trust[a]++;
            be_trusted[b]++;
        }
        int cnt = 0, ans = -1;
        for (int i = 1; i <= n; i++) {
            if (trust[i]==0 && be_trusted[i]==n-1) {
                cnt++; ans = i;
                if (cnt >= 2) break;
            }
        }
        if (cnt==1) return ans;
        return -1;
    }
};