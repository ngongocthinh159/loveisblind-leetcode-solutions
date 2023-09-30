class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int wordLen = words[0].size();
    int totalWord = words.size();
    if (s.size() < wordLen*totalWord) return vector<int>();
    unordered_map<string,int> map;
    vector<int> res;
    for (int i = 0; i < words.size(); i++) {
      map[words[i]]++;
    }
    
    unordered_map<string,int> map2;
    for (int i = 0; i <= wordLen - 1; i++) {
      int j = i;
      int start = i;
      int matched = 0;

      while (j + wordLen - 1 <= s.size() - 1) {
        string word = s.substr(j, wordLen);

        if (map.find(word) == map.end()) {
          map2.clear();
          j += wordLen;
          start = j;
          matched = 0;
          continue;
        }

        int& cnt1 = map[word];
        int& cnt2 = ++map2[word];

        if (cnt1 > cnt2) {
          matched++;
          j += wordLen;
        } else if (cnt1 == cnt2) {
          matched++;
          if (matched == totalWord) {
            res.push_back(start);
          }
          j += wordLen;
        } else if (cnt1 < cnt2) {
          matched--;
          do {
            string startWord = s.substr(start, wordLen);
            int& c1 = map[startWord];
            int& c2 = map2[startWord];
            c2--;
            if (c1 != c2) matched--;
            else matched++;
            start += wordLen;
            if (matched == totalWord) {
              res.push_back(start);
            }
          } while (cnt1 < cnt2);
          j += wordLen;
        }
      }
      map2.clear();
    }
    return res;
  }
};