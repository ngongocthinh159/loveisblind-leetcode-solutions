unordered_map<char,int> mp;
class Solution {
public:
    struct comparator {
        bool operator() (char &c1, char &c2) {
            return mp[c1] < mp[c2];
        }
    };
    string customSortString(string order, string s) {
        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        for (int i = 0; i < 26; i++) {
            if (!mp.count(i+'a')) mp[i+'a'] = mp.size();
        }
        sort(s.begin(),s.end(),comparator());
        return s;
    }
};