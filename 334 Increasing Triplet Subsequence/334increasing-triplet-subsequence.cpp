#define ll long long
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ll mn = LONG_LONG_MAX, second_mn = LONG_LONG_MAX;
        for (auto x : nums) {
            if (x <= mn) {
                mn = x;
            } else if (x <= second_mn) {
                second_mn = x;
            } else return true;
        }
        return false;
    }
};