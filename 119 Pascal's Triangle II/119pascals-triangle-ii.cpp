class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v = {1};
        for (int i = 1; i <= rowIndex; i++) {
            v.push_back(1);
            for (int j = v.size() - 2; j >= 1; j--) {
                v[j] = v[j] + v[j - 1];
            }
        }
        return v;
    }
};