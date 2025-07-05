class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501]{};
        for (auto x : arr) freq[x]++;
        for (int i = 500; i >= 1; i--) if (freq[i] == i)
            return i;
        return -1;
    }
};