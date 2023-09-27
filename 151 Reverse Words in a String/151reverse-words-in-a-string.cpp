class Solution {
public:
    string reverseWords(string s) {
        // vector<string> v;
        // string res = "";
        // stringstream ss(s);
        // string word;
        // while (ss >> word) {
        //     v.push_back(word);
        // }
        // for (int i = v.size() - 1; i >= 0; i--) {
        //     res += v[i];
        //     if (i != 0) res += " ";
        // } 
        // return res;

        int i = 0;
        string res = "";
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            if (i == s.size()) break;

            string word = "";
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            for (int j = 0; j < word.size()/2; j++) {
                char tmp = word[j];
                word[j] = word[word.size() - 1 - j];
                word[word.size() - 1 - j] = tmp;
            }
            if (word != "" && res.size() > 0) res += " ";
            res += word;
        }
        for (int j = 0; j < res.size()/2; j++) {
            char tmp = res[j];
            res[j] = res[res.size() - 1 - j];
            res[res.size() - 1 - j] = tmp;
        }
        return res;
    }
};