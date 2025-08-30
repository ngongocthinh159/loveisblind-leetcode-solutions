class Solution {
public:
    const double EPS = 1e-6;
    vector<double> res(double &a, double &b) {
        vector<double> ans = {a + b, a - b, b - a, a * b};
        if (a) ans.push_back(b / a);
        if (b) ans.push_back(a / b);
        return ans;
    }
    bool dfs(vector<double> &c) {
        if (c.size() == 1)
            return 24.00 - EPS <= c[0] && c[0] <= 24.00 + EPS;
        for (int i = 0; i < c.size(); i++) 
            for (int j = i + 1; j < c.size(); j++) {
                vector<double> nc;
                for (int k = 0; k < c.size(); k++) if (k != i && k != j)
                    nc.push_back(c[k]);
                for (auto r : res(c[i], c[j])) {
                    nc.push_back(r);
                    if (dfs(nc)) return true;
                    nc.pop_back();
                }
            }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> c(cards.begin(), cards.end());
        return dfs(c);
    }
};