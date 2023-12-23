class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        unordered_map<char,pair<int,int>> mp;
        mp['N'] = {-1, 0};
        mp['S'] = {1, 0};
        mp['W'] = {0, -1};
        mp['E'] = {0, 1};
        st.insert({0,0});
        int x = 0, y = 0;
        for (int i = 0; i < path.size(); i++) {
            auto p = mp[path[i]];
            int X = x + p.first;
            int Y = y + p.second;
            if (st.count({X, Y})) {
                return true;
            }
            st.insert({X, Y}); x = X; y = Y;
        }
        return false;
    }
};