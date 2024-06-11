class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        vector<int> cnt(1e3 + 5);
        for (auto x : arr1) cnt[x]++;
        for (auto x : arr2) {
            for (int i = 0; i < cnt[x]; i++) {
                res.push_back(x);
            }
            cnt[x] = 0;
        }
        for (int i = 0; i < 1e3 + 5; i++) {
            if (cnt[i]) {
                for (int j = 0; j < cnt[i]; j++) res.push_back(i);
                cnt[i] = 0;
            }
        }
        return res;
        
    }
};