class Solution {
public:
    int query(int l, int r, vector<int> &pre) {
        return pre[r + 1] - pre[l];
    }
    vector<int> decrypt(vector<int>& code, int K) {
        int n = code.size();
        int k = abs(K);
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + code[i - 1];
        for (int i = 0; i < n; i++) {
            if (K == 0) code[i] = 0;
            else if (K > 0) {
                if (i + k >= n) {
                    code[i] = query(i + 1, n - 1, pre);
                    code[i] += query(0, k - (n - 1 - i) - 1, pre);
                } else code[i] = query(i + 1, i + k, pre);
            } else {
                if (i < k) {
                    code[i] = query(0, i - 1, pre);
                    int len = i - 1 - 0 + 1;
                    code[i] += query(n - (k - len), n - 1, pre);
                } else {
                    code[i] = query(i - k, i - 1, pre);
                }
            }
        }
        return code;
    }
};