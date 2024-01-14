class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int remain = 0;
        vector<int> v;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int cur = digits[i];
            if (i == digits.size() - 1) cur += 1;
            cur += remain;
            v.push_back(cur%10);
            remain = cur/10;
        }
        if (remain != 0) v.push_back(remain);
        reverse(v.begin(), v.end());
        return v;
    }
};