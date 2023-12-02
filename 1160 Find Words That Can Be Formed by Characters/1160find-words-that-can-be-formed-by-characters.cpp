class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < chars.size(); i++) {
            cnt[chars[i] - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            string cur = words[i];
            vector<int> prev = cnt;
            bool ok = true;

            for (int j = 0; j < cur.size(); j++) {
                if (cnt[cur[j] - 'a'] > 0) cnt[cur[j] - 'a']--;
                else {
                    ok = false; break;
                }    
            }
            if (ok) res += cur.size();

            cnt = prev;
        }
        return res;
    }
};