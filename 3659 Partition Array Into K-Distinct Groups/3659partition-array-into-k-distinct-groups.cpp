class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        int g = n / k;
        unordered_map<int,int> f;
        for (auto x : nums) f[x]++;
        for (auto &[x, cnt] : f) if (cnt > g)
            return false;
        return true;
    }
};