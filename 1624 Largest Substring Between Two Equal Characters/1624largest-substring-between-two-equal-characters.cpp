class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<pair<int,int>> cnt(26, {-1,-1});
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (cnt[c - 'a'].first == -1) cnt[c - 'a'] = {i, -1};
            else cnt[c - 'a'] = {cnt[c - 'a'].first, i};
        }
        int mx = -1;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i].first != -1 && cnt[i].second != -1)
                mx = max(mx, cnt[i].second - cnt[i].first - 1);
        }
        return mx;
    }
};