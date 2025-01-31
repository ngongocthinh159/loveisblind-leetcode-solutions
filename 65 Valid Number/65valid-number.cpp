class Solution {
public:
    bool isNumber(string s) {
        vector<unordered_map<string,int>> g = {
            // start state
            { {"digit", 1}, {"sign", 2}, {"dot", 4} }, // 0 (not ok)

            { {"digit", 1}, {"expo", 6}, {"dot", 5} }, // 1

            { {"digit", 3}, {"dot", 4} }, // 2 (not ok)

            { {"digit", 3}, {"dot", 5}, {"expo", 6} }, // 3

            { {"digit", 5} }, // 4 (not ok)

            { {"digit", 5}, {"expo", 6} }, // 5

            { {"digit", 8}, {"sign", 7} }, // 6 (not ok)

            { {"digit", 8} }, // 7 (not ok)

            { {"digit", 8} }, // 8
        };

        unordered_set<int> S = {0, 2, 4, 6, 7};
        int state = 0;
        for (auto c : s) {
            string edge;
            if (0 <= (c - '0') && (c - '0') <= 9) edge = "digit";
            if (c == 'E' || c == 'e') edge = "expo";
            if (c == '+' || c == '-') edge = "sign";
            if (c == '.') edge = "dot";
            if (!g[state].count(edge)) return false;
            state = g[state][edge];
        }
        return !S.count(state);
    }
};