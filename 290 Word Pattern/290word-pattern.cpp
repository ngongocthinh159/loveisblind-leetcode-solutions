class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        int i = 0;
        unordered_map<char,string> mp;
        set<string> st;
        while (ss >> word) {
            if (i == pattern.size()) return false;
            if (mp.find(pattern[i]) == mp.end()) {
                if (st.find(word) == st.end()) {mp[pattern[i]] = word; st.insert(word);}
                else return false;
            } else {
                string& tmp = mp[pattern[i]];
                if (tmp != word) return false;
            }

            i++;
        }
        if (i != pattern.size()) return false;
        return true;
    }
};