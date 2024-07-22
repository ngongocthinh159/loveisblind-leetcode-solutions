class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, vector<string>> M;
        int n = names.size();
        for (int i = 0; i < n; i++) {
            M[heights[i]].push_back(names[i]);
        }
        vector<string> res;
        for (auto &[key, list] : M) {
            for (auto &name : list) res.push_back(name);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};