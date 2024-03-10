class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>S1,S2;
        for(auto num : nums1)
            S1.insert(num);
        for (auto num : nums2) {
            if (S1.count(num)) S2.insert(num);
        }
        return vector<int>(S2.begin(),S2.end());
    }
};