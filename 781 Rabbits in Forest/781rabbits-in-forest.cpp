class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> freq;
        for (auto x : answers) freq[x]++;
        int ans = 0;
        for (auto &[id, cnt] : freq) {
            ans += ((cnt + id) / (id + 1)) * (id + 1);
        }
        return ans;
    }
};