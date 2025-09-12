class Solution {
public:
    unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool isv(char c) {
        return vow.count(c);
    }
    string sortVowels(string s) {
        vector<int> v;
        for (auto c : s) if (isv(c)) v.push_back(c);
        sort(v.begin(), v.end());
        string t = s;
        int i = 0;
        for (auto &c : t) if (isv(c)) c = v[i++];
        return t;
    }
};