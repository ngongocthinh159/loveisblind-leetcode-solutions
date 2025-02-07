class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> freq, color;
        vector<int> ans(queries.size());
        int dif = 0, i = 0;
        for (auto &q : queries) {
            if (color[q[0]] && --freq[color[q[0]]] == 0) dif--;
            if (++freq[q[1]] == 1) dif++;
            color[q[0]] = q[1];
            ans[i++] = dif;
        }
        return ans;
    }
};