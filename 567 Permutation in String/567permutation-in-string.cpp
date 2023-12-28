class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }
        int matched = 0;
        for (int i = 0; i < c1.size(); i++) {
            if (c1[i] == c2[i]) matched++;
        }
        if (matched == 26) return true;
        int k = s1.size();
        for (int i = s1.size(); i < s2.size(); i++) {
            c2[s2[i] - 'a']++;
            if (c2[s2[i] - 'a'] - 1 == c1[s2[i] - 'a']) matched--;
            else if (c2[s2[i] - 'a'] == c1[s2[i] - 'a']) matched++;

            c2[s2[i - k] - 'a']--;
            if (c2[s2[i - k] - 'a'] + 1 == c1[s2[i - k] - 'a']) matched--;
            else if (c2[s2[i - k] - 'a'] == c1[s2[i - k] - 'a']) matched++;

            if (matched == 26) return true;
        }
        return false;
    }
};