class Solution {
public:
    struct comparator {
        bool operator() (const pair<int,int> &v1, const pair<int,int> &v2) const {
            if (v1.second < v2.second) return true;
            if (v1.second == v2.second && v1.first > v2.first) return true;
            return false;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> cnt(201);
        for (int x : nums) {
            cnt[x + 100]++;
        }
        vector<pair<int,int>> res;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] != 0) res.push_back({i - 100, cnt[i]});
        }
        sort(res.begin(), res.end(), comparator());
        vector<int> ans;
        for (auto &p : res) {
            for (auto i = 0; i < p.second; i++) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};