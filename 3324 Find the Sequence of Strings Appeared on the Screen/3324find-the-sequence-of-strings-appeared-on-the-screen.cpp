class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string last = "";
        for (int i = 0; i < target.size(); i++) {
            char cur = 'a';
            last += cur;
            ans.push_back(last);
            while (cur < target[i]) {
                cur++;
                last[last.size() - 1] = cur;
                ans.push_back(last);
            }
        }
        return ans;
    }
};