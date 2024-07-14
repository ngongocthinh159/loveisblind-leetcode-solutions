class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> v;
        int n = positions.size();
        for (int i = 0; i < n; i++) {
            v.push_back({positions[i], healths[i], (directions[i] == 'R' ? 0 : 1), i});
        }
        sort(v.begin(), v.end());
        vector<vector<int>> stack;
        int p, h, d, idx;
        int p1, h1, d1, idx1;
        vector<vector<int>> tmp;
        for (int i = 0; i < n; i++) {
            p = v[i][0];
            h = v[i][1];
            d = v[i][2];
            idx = v[i][3];
            if (d == 0) {
                stack.push_back(v[i]);
            } else if (d == 1) {
                if (stack.size()) {
                    vector<int> top = stack.back(); stack.pop_back();
                    p1 = top[0];
                    h1 = top[1];
                    d1 = top[2];
                    idx1 = top[3];
                    if (h1 > h) {
                        h1--;
                        if (h1 > 0) {
                            stack.push_back({p1, h1, d1, idx1});
                        }
                    } else if (h1 < h) {
                        v[i][1]--;
                        if (v[i][1] > 0) {
                            i--;
                        }
                    }
                } else {
                    tmp.push_back(v[i]);
                }
            }
        }
        for (int i = 0; i < stack.size(); i++) tmp.push_back(stack[i]);
        vector<pair<int,int>> res;
        for (int i = 0; i < tmp.size(); i++) {
            res.push_back({tmp[i][3], tmp[i][1]});
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for (auto &x : res) {
            ans.push_back(x.second);
        }
        return ans;
    }
};