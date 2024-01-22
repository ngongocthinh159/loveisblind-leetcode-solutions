class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        int twice, miss, sum = 0, n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (st.count(nums[i])) {twice = nums[i];}
            st.insert(nums[i]);
            sum += nums[i];
        }
        miss = n*(n+1)/2-sum+twice;
        return {twice, miss};
    }
};