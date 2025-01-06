class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int cnt = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] += cnt + (i == 0 ? 0 : ans[i - 1]);
            cnt += (boxes[i] == '1');
        }
        vector<int> ans2(n);
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans2[i] += cnt + (i == n - 1 ? 0 : ans2[i + 1]);
            cnt += (boxes[i] == '1');
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = ans[i] + ans2[i];
        return res;
    }
};