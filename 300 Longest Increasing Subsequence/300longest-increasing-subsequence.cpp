class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (auto num : nums) {
            auto it = lower_bound(sub.begin(), sub.end(), num);
            if (it == sub.end()) {sub.push_back(num); continue;}
            int idx = it - sub.begin();
            sub[idx] = num;
        }
        return sub.size();
    }
};