class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt1(1001);
        vector<int> cnt2(1001);
        for (auto x : nums1) cnt1[x]++;
        for (auto x : nums2) cnt2[x]++;
        vector<int> ans;
        for (int i = 0; i < cnt1.size(); i++) {
            int will = min(cnt1[i], cnt2[i]);
            for (int j = 0; j < will; j++) ans.push_back(i);
        }
        return ans;
    }
};