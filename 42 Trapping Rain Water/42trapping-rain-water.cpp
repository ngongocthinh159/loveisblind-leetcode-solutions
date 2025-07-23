class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> L(n + 1), R(n + 2);
        for (int i = 0; i < n; i++) {
            L[i + 1] = max(L[i], height[i]);
        }   
        for (int i = n - 1; i >= 0; i--) {
            R[i + 1] = max(R[i + 2], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(0, min(L[i], R[i + 2]) - height[i]);
        }
        return ans;
    }
};