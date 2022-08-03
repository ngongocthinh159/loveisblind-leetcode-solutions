class Solution {
public:
    bool sumLessThanOrEqual(int m, vector<int>& nums, int threshold) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (ceil((float) nums[i] / m));
        }
        // cout << m << " " << sum << "\n";
        
        return sum <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        
        int l = 1, r = nums[nums.size() - 1];
        
        while (l < r) {
            int m = l + ((r - l) >> 1);
            
            if (sumLessThanOrEqual(m, nums, threshold)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        return r;
    }
};