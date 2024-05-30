class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,pair<int,int>> M;
        M[0] = {0, 1};
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur = cur ^ arr[i];
            auto _ = M[cur];
            int neg = _.first;
            int cnt = _.second;
            if (cnt > 0) ans += (i + 1)*cnt - (neg + cnt);
            
            M[cur] = {neg + i + 1, cnt + 1};
        }
        return ans;
    }
};