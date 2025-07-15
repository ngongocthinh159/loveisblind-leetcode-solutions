class Solution {
public:
    vector<char> v={'a', 'e', 'i', 'o', 'u'};
    bool isV(char c) {  
        for (auto _c : v) if (c==_c) return true;
        return false;
    }
    bool isValid(string word) {
        bool len3 = word.size() >= 3;
        bool vow = false;
        bool con = false;
        for (auto c : word) {
            if (!('0' <= c && c <= '9') && !('a' <= c && c <= 'z') && 
                !('A' <= c && c <= 'Z')) 
                return false;
            if (!('0' <= c && c <= '9')) {
                if ('A' <= c && c <= 'Z')
                    c = c - 'A' + 'a';
                if (isV(c))
                    vow = true;
                else
                    con = true;
            }
        }
        return len3 && vow && con;
    }
};