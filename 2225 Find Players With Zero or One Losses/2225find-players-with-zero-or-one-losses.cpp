class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        unordered_set<int> st;
        for (int i = 0; i < matches.size(); i++) {
            int win = matches[i][0];
            int lose = matches[i][1];
            mp1[lose]++;
            st.insert(win);
            st.insert(lose);
        }
        vector<int> res;
        vector<int> res1;
        for (auto num : st) {
            if (!mp1.count(num)) res.push_back(num);
            else if (mp1[num] == 1) res1.push_back(num);
        }
        sort(res.begin(), res.end());
        sort(res1.begin(), res1.end());
        return {res, res1};
    }
};