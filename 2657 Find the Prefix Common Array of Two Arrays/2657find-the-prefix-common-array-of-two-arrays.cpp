class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        long long SA = 0, SB = 0;
        int n = A.size();
        vector<int> ans(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            SA |= (1LL << A[i]);
            SB |= (1LL << B[i]);
            if (A[i] == B[i]) cnt++;
            else {
                if (SB & (1LL << A[i]))cnt++;
                if (SA & (1LL << B[i]))cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};