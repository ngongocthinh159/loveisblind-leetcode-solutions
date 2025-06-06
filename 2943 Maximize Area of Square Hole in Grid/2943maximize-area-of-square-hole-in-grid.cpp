class Solution {
public:
    int findMax(vector<int>& hBars) {
        int mxH = 1;
        for (int i = 0; i < hBars.size();) {
            int start = hBars[i];
            int j = i;
            while (j + 1 < hBars.size() && hBars[j + 1] - hBars[j] == 1) {
                j++;
            }
            int len = j - i + 1;
            mxH = max(mxH, len + 1);
            i = j + 1;
        }
        return mxH;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int len = min(findMax(hBars), findMax(vBars));
        return len * len;
    }
};