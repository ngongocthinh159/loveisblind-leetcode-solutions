class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> arr;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < nums[i].size(); j++) arr.push_back({nums[i][j], i});
        sort(arr.begin(), arr.end());
        int l = 0, _l = nums[0][0], _r = nums[0][0], range = INT_MAX;
        int diff = 0;
        vector<int> freq(n);
        for (int r = 0; r < arr.size(); r++) {
            freq[arr[r].second]++;
            if (freq[arr[r].second] == 1) diff++;

            while (l <= r && diff >= n) {
                if (range > arr[r].first - arr[l].first + 1) {
                    range = arr[r].first - arr[l].first + 1;
                    _l = arr[l].first, _r = arr[r].first;
                }
                freq[arr[l].second]--;
                if (freq[arr[l].second] == 0) diff--;
                l++;
            }
        }
        return {_l, _r};
    }
};