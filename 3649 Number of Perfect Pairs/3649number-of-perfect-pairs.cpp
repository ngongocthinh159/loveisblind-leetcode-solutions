class Solution {
public:
    /*
        Suppose a and b have same sign or different sign, the second condition always correct
            => Never need to check second condition

        Suppose a and b same sign, simplify to:
            |a - b| <= min(|a|, |b|)
                |a| > |b|
                    |a| - |b| <= |b|
                    |a| <= 2 * |b|

                |a| < |b|
                    |b| - |a| <= |a|
                    2*|a| >= |b|

                => ceil(|b|/2) <= |a| <= 2 * |b|

        Suppose a and b dif sign, simplify to:
            |a + b| <= min(|a|, |b|)
                |a| > |b|
                    |a| - |b| <= |b|
                    |a| <= 2*|b|

                |a| < |b|
                    |b| - |a| <= |a|
                    |a| >= ceil(|b|/2)
                
                => ceil(|b|/2) <= |a| <= 2 * |b|

        => Two cases have same condition:
            ceil(|b|/2) <= |a| <= 2 * |b|
    */
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = abs(nums[i]);
        sort(v.begin(), v.end());
        long long ans = 0;
        for (int i = 0, j = 0, k = 0; i < n; i++) {
            while (j < n && !(2 * v[j] >= v[i])) j++;
            while (k < n && 2 * v[i] >= v[k]) k++;
            ans += max(0, (i - 1) - j + 1);
            ans += max(0, k - 1 - (i + 1) + 1);
        }
        return ans / 2;
    }
};