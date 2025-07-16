class Solution {
public:
    int cal(int prev, vector<int> &nums) {
        int cnt = 0;
        for (auto x : nums) {
            if ((x + prev) & 1) {
                cnt++;
                prev = x;
            }
        }
        return cnt;
    }
    int maximumLength(vector<int>& nums) {
        int n = nums.size(); 
        int odd = 0, even = 0;
        for (auto x : nums) {
            if (x&1) odd++;
            else even++;
        }
        return max(cal(0, nums), max(cal(1, nums), max(odd, even)));
    }
};