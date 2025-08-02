class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        const int IINF = 1e9;
        vector<int> bit(32, -1);
        int n = arr.size();
        unordered_set<int> S;
        bool hasZero = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) hasZero = 1;
            for (int j = 0; j < 32; j++) if ((arr[i] >> j) & 1)
                bit[j] = i;
            vector<pair<int,int>> v;
            for (int j = 0; j < 32; j++) if (bit[j] != -1) v.push_back({bit[j], j});
            sort(v.begin(), v.end(), greater<>());
            int k = 0;
            int cur = 0;
            while (k < v.size()) {
                int s = v[k].first;
                while (k < v.size() && v[k].first == s) {
                    cur |= (1 << v[k].second);
                    k++;
                }
                S.insert(cur);
            }
        }
        return (int) S.size() + hasZero;
    }
};