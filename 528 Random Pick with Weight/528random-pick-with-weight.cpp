class Solution {
public:
    vector<int> tmp;
    int mn = 0, mx = 0;
    Solution(vector<int>& w) {
        tmp.resize(w.size() + 1);
        tmp[0] = 0;
        for (int i = 0; i < w.size(); i++) {
            mx += w[i];
            tmp[i + 1] = tmp[i] + w[i];
        }
        mx--;
    }
    
    int pickIndex() {
        int R = mn + rand() % (mx - mn + 1);
        int l = -1, r = tmp.size();
        while (r - l > 1) {
            int m = l + (r - l)/2;
            if (tmp[m] > R)
                r = m;
            else
                l = m;
        }
        return r - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */