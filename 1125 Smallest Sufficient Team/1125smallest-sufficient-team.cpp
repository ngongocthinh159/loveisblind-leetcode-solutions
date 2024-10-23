class Solution {
public:
    const int INF = 1e9;
    int n;
    int m;
    vector<int> person_skills;
    vector<int> res;
    int mn = INT_MAX;
    vector<vector<int>> dp;
    bool ok = false;
    int dfs(int i, int mask) {
        if (mask == ((1 << m) - 1)) {
            return 0;
        }
        if (i == n) return INF;
        if (dp[i][mask] != -1) return dp[i][mask];

        int res = INF;
        if (dfs(i + 1, mask) != INF) {
            res = min(res, dfs(i + 1, mask));
        }
        if (dfs(i + 1, mask | person_skills[i]) != INF) {
            res = min(res, dfs(i + 1, mask | person_skills[i]) + 1);
        }

        return dp[i][mask] = res;
    }
    void pathConstruction() {
        int mask = 0;
        for (int i = 0; i < n; i++) {
            int notChosen = dfs(i + 1, mask);
            int chosen = dfs(i + 1, mask | person_skills[i]);
            if (notChosen != INF && chosen != INF) {
                if (notChosen > chosen + 1) {
                    res.push_back(i);
                    mask = mask | person_skills[i];
                }
            } else if (chosen != INF) {
                res.push_back(i);
                mask = mask | person_skills[i];
            }
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = people.size();
        m = req_skills.size();
        unordered_map<string,int> M;
        for (int i = 0; i < req_skills.size(); i++) {
            M[req_skills[i]] = i;
        }
        person_skills.resize(n);
        for (int i = 0; i < people.size(); i++) {
            int mask = 0;
            for (auto &skill : people[i]) {
                mask = mask | (1 << M[skill]);
            }
            person_skills[i] = mask;
        }
        dp = vector<vector<int>>(n,
            vector<int>((1 << m), -1));
        int minChosen = dfs(0, 0);
        pathConstruction();
        return res;
    }
};