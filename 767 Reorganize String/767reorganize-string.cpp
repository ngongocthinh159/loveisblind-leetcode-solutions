class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26, 0);
        priority_queue<pair<int,char>> pq;
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i]) pq.push({cnt[i], 'a' + i});
        }
        string res="";
        while (pq.size()) {
            auto cur = pq.top(); pq.pop();
            if (res == "" || res.back() != cur.second) {
                res += cur.second; 
                if (cur.first - 1 > 0) pq.push({cur.first - 1, cur.second});
            }
            else {
                if (!pq.size()) return "";
                auto sec = pq.top(); pq.pop();
                res += sec.second;
                if (sec.first - 1 > 0) pq.push({sec.first - 1, sec.second});
                pq.push(cur);
            }
        }
        return res;
    }
};