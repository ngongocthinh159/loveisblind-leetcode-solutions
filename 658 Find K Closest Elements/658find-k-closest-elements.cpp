class Solution {
public:
    int getCost(int l, int r, vector<int>& arr, int x, vector<int>&prf) {
        auto idx = upper_bound(arr.begin() + l, arr.begin() + r + 1, x);
        int i = idx - arr.begin();
        int cost = 0;

        if (i <= r) {
            cost += prf[r] - prf[i] + arr[i] - (r - i + 1)*x;
        }
        if (i - 1 >= l) {
            cost += (i - 1 - l + 1)*x - (prf[i - 1] - prf[l] + arr[l]);
        }
        return cost;
    } 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end());
        vector<int> prf(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            prf[i] = i == 0 ? arr[i] : arr[i] + prf[i - 1];
        }
        int ans = INT_MAX, _l = -1, _r = -1;
        for (int r = k - 1; r < arr.size(); r++) {
            int cost = getCost(r - k + 1, r, arr, x, prf);
            if (ans > cost) {
                ans = cost; _l = r - k + 1; _r = r;
            }
        }
        vector<int> res;
        for (int i = _l; i <= _r; i++)
            res.push_back(arr[i]);
        return res;
    }
};