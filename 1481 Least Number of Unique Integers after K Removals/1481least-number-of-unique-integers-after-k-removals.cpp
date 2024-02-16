class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        vector<int> cnt(arr.size() + 1, 0);
        for (auto num : arr) {
            mp[num]++;
        }
        for (auto [key,val] : mp) {
            cnt[val]++;
        }
        int remove = 0;
        for (int i = 1; i <= arr.size(); i++) {
            if (cnt[i] != 0) {
                int willRemove = min(k/i,cnt[i]);
                remove += willRemove;
                k -= willRemove*i;
                cnt[i] -= willRemove;
                if (cnt[i]!=0) break;
            }
        }
        return (int) mp.size() - remove;
    }
};