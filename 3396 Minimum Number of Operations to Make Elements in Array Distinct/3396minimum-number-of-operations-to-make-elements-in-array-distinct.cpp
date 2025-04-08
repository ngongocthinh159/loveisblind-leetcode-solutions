class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        bitset<105> S;
        for (int i = n - 1; i >= 0; i--) {
            if (S[nums[i]]) break;
            S[nums[i]] = 1;
            cnt++;
        }
        return (n - cnt + 2) / 3;
    }
};