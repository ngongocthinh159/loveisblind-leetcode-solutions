class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (derived[i] == 1) {
                cur = cur^0^1;
            }
        }
        return cur == 0;
    }
};