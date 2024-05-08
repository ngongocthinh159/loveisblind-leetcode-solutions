class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int> scoreToIdx;
        for (int i = 0; i < score.size(); i++) {
            scoreToIdx[score[i]] = i;
        }
        sort(score.begin(), score.end(), greater<int>());
        vector<string> ans(score.size());
        for (int i = 0; i < score.size(); i++) {
            if (i == 0) ans[scoreToIdx[score[i]]] = "Gold Medal";
            else if (i == 1) ans[scoreToIdx[score[i]]] = "Silver Medal";
            else if (i == 2) ans[scoreToIdx[score[i]]] = "Bronze Medal";
            else ans[scoreToIdx[score[i]]] = to_string(i + 1);
        }
        return ans;
    }
};