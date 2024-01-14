class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        unordered_set<char> s1;
        unordered_set<char> s2;
        for (int i = 0; i < word1.size(); i++) {
            cnt1[word1[i] - 'a']++;
            s1.insert(word1[i]);
        }
        for (int i = 0; i < word2.size(); i++) {
            cnt2[word2[i] - 'a']++;
            s2.insert(word2[i]);
        }
        if (s1 != s2) return false;
        vector<int> v1;
        vector<int> v2;
        for (int i = 0; i < cnt1.size(); i++) {
            if (cnt1[i] != 0) v1.push_back(cnt1[i]);
            if (cnt2[i] != 0) v2.push_back(cnt2[i]);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};