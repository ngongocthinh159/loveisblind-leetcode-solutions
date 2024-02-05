class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> fact = {1};
        for (int i = 1; i <=n; i++) {
            nums.push_back(i);
            fact.push_back(i*fact.back());
        }
        string res = "";
        for (int i = n - 1; i >= 0; i--) {
            int idx = ceil((double)k/fact[i]) - 1;
            res += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            // cout << idx << " " << idx*fact[i] << "\n";
            k -= idx*fact[i];
        }
        return res;
    }
};