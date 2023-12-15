class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;
        for (auto path : paths) {
            mp[path[0]]++;
            if (!mp.count(path[1])) mp[path[1]];
        }
        for (auto [city, size] : mp) {
            if (!size) return city;
        }
        return "";
    }
};