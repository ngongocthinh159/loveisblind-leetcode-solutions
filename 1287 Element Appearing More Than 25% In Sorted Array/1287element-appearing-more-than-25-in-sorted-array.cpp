class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int freq = n/4;
        int i = 0;
        while (i < n) {
            int s = arr[i];
            int cnt = 1; i++;
            while (i < n && arr[i] == arr[i - 1]) {
                cnt++; i++;
            }
            if (cnt > freq) return s;
        }
        return -1;
    }
};