class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt = 0;
        int mx = -1;
        for (int i = 0; i < arr.size(); i++) {
            mx = max(mx, arr[i]);
            if (mx == i) cnt++;
        }
        return cnt;
    }
};