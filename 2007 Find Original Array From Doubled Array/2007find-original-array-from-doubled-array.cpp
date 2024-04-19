class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset<int> S;
        for (int i = 0; i < changed.size(); i++) {
            S.insert(changed[i]);
        }
        vector<int> res;
        bool ok = true;
        while (S.size()) {
            int highest = *prev(S.end());
            if (highest >= 0) {
                if (highest&1) {ok = false; break;}
                auto it = S.find(highest/2);
                if (it == S.end()) {ok = false; break;}
                else S.erase(it);
            } else {
                auto it = S.find(highest*2);
                if (it == S.end()) {ok = false; break;}
                else S.erase(S.find(highest*2));
            }
            auto it = S.find(highest);
            if (it == S.end()) {ok = false;break;}
            else {res.push_back(highest >= 0 ? highest/2 : highest); S.erase(S.find(highest));}
        }
        if (ok) return res;
        else return {};
    }
};