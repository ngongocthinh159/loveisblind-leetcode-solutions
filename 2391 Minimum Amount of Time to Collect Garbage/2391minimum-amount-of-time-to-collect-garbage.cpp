class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sum = 0;
        bool G = false, P = false, M = false;
        for (int i = garbage.size() - 1; i >= 0; i--) {
            sum += garbage[i].size();
            for (int j = 0; j < garbage[i].size(); j++) {
                if (garbage[i][j] == 'G') G = true;
                if (garbage[i][j] == 'P') P = true;
                if (garbage[i][j] == 'M') M = true;
            }
            if (i > 0 && G) sum += travel[i - 1];
            if (i > 0 && P) sum += travel[i - 1];
            if (i > 0 && M) sum += travel[i - 1];
        }
        return sum;
    }
};