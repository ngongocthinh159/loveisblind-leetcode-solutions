class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // First observation: we can always pick "ab" over "ba" first if x > y
        // becuz we only in the situation that we can pick either "ab" or "ba" if 
        // we have a substr "aba" or "bab", so in either substr if we remove "ab" or "ba"
        // then the remaining character will remain the same, indistinguishable
        // so as long as we can pick the larger we always pick

        // Second observation: if we pick one "ab", it will not effect the existence of other "ab"
        // so given string s with mutiple position "ab" we can pick, then we can pick any them, order is not matter

        // Third observation: after picking all "ab" possible, the remaining s will contain "ba"
        // and only contain "ba" for any way of removal
        // Consider the case when "ab" is not existed anymore, we string s of form:
        // bbbbbaaaaaaaa => nerver can create ab anymore

        int n = s.size();
        string sm = "ab", lg = "ba";
        if (x > y) {
            swap(x, y);
            swap(sm, lg);
        } 
        vector<char> v;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v.size() && v.back() == lg[0] && s[i] == lg[1]) {
                ans += y;
                v.pop_back();
            } else {
                v.push_back(s[i]);
            }
        }
        vector<char> st;
        for (int i = 0; i < v.size(); i++) {
            if (st.size() && st.back() == sm[0] && v[i] == sm[1]) {
                ans += x;
                st.pop_back();
            } else {
                st.push_back(v[i]);
            }
        }
        return ans;
    }
};