class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while (j - 1 >= 0 && arr[j - 1] <= arr[j]) {
            j--;
        }
        while (i + 1 < n && arr[i + 1] >= arr[i]) {
            i++;
        }
        int ans = max(i + 1, n - j);
        int mxI = i;
        i = -1;
        while (j < n) {
            while (i + 1 < j && arr[i + 1] <= arr[j] && i + 1 <= mxI) {
                i++;
            }

            ans = max(ans, (n - j) + i + 1);

            j++;
        }
        return n - ans;
    }
};