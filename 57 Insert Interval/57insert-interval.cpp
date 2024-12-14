class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        set<pair<int,int>> S;
        for (auto &v : intervals) S.insert({v[0], v[1]});
        int start = newInterval[0];
        int end = newInterval[1];
        auto l = S.lower_bound({start, INT_MAX});
        auto r = S.upper_bound({end, INT_MAX});
        if (l != S.begin()) {
            l--;
            if (l->second < start) l++;
        }
        if (l != r) {
            start = min(l->first, start);
            end = max((--r)->second, end);
            S.erase(l, ++r);
        }
        S.insert({start, end});
        vector<vector<int>> res;
        for (auto p : S) res.push_back({p.first, p.second});
        return res;
    }
};