class Solution {
public:
    vector<int> grayCode(int n) {
        if (n== 1) return {0, 1};
        auto left = grayCode(n - 1);
        auto right = left;
        reverse(right.begin(), right.end());
        for (auto &x : right) left.push_back(x + pow(2, n - 1));
        return left;
    }
};