class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (auto num : nums) {
            if (num > 0) pos.push_back(num);
            else neg.push_back(num);
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i+=2) {
            nums[i] = pos[j]; nums[i+1] = neg[j]; j++; 
        }
        return nums;
    }
};