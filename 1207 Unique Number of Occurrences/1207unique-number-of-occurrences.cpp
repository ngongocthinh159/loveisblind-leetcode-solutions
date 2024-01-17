class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for (auto num : arr) {
            mp[num]++;
        }
        for (auto &[key, val]: mp) {
            if (st.count(val)) return false;
            st.insert(val);
        }
        return true;
    }
};