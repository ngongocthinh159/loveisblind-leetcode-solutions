class Solution {
public:
    unordered_set<char> S = {'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char c) {
        return S.count(c);
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1]) ? 1 : 0);
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) ans[i] = pref[queries[i][1] + 1] - pref[queries[i][0]];
        return ans; 
    }
};