class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int mx = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                score++;
                i++;
                mx = max(mx,score); 
            } else if (score >= 1) {
                score--;
                power += tokens[j];
                j--;
            } else {
                break;
            }
        }
        return mx;
    }
};