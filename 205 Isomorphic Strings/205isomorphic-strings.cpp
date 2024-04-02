class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> v1(s.size());
        vector<int> v2(t.size());
        unordered_map<char,char> M1;
        unordered_map<char,char> M2;
        for (int i = 0; i < s.size(); i++) {
            if (!M1.count(s[i])) M1[s[i]] = i;
            v1[i] = M1[s[i]];
            if (!M2.count(t[i])) M2[t[i]] = i;
            v2[i] = M2[t[i]];
        }
        return v1 == v2;
    }
};