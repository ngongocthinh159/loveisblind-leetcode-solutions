class Solution {
public:
    int _i = -1, _j = -1;
    bool check(double x, vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        double local_mx = -1.0;
        int local_i = -1, local_j = -1;
        for (int i = 0; i < n - 1; i++) {
            int l = i, r = n;
            while (r - l > 1) {
                int m = l + (r - l)/2;
                bool ok = ((double) arr[i]/arr[m]) <= x; 
                if (ok) {
                    if (local_mx < (double) arr[i]/arr[m]) {
                        local_mx = (double) arr[i]/arr[m];
                        local_i = arr[i], local_j = arr[m];
                    }
                    r = m;
                } else {
                    l = m;
                }
            }
            cnt += (n - 1) - r + 1;
        }

        if (cnt >= k) {
            _i = local_i, _j = local_j;
        }

        return cnt >= k;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1;
        for (int i = 0; i < 30; i++) {
            double m = l + (double) (r - l)/2;
            if (check(m, arr, k)) {
                r = m;
            } else {
                l = m;
            }
        }
        return {_i, _j};
    }
};