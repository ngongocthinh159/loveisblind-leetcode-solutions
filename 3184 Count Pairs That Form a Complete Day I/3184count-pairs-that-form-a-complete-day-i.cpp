class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int> M;
        int remain;
        int ans = 0;
        for (int i = 0; i < hours.size(); i++) {
            remain = hours[i] % 24;
            if (M.count(24 - remain)) ans += M[24 - remain];
            if (remain == 0 && M.count(0)) ans += M[0];
            M[remain]++;
        }
        return ans;
    }
};