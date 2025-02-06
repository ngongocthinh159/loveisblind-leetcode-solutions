class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) freq[nums[i]*nums[j]]++;
        int ans = 0;
        for (auto [_, cnt] : freq) if (cnt >= 2) ans += 8*cnt*(cnt - 1)/2;
        return ans;
    }
};