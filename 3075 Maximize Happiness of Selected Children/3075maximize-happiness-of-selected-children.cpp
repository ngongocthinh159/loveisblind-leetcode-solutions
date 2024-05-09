class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        long long res = 0;
        int i = n - 1;
        for (int turn = 0; turn < k; turn++) {
            if (happiness[i] - turn > 0) res = res + happiness[i] - turn;
            else break;
            i--;
        }
        return res;
    }
};