class Solution {
public:
    int go(int x, int y, const vector<int> &m, vector<vector<int>> &g) {
        int cnt = 0;
        int val = g[x][y];
        while (g[x][y] == val) {
            cnt++;
            x += m[0];
            y += m[1];
            if (cnt == 3)
                return val;
        }
        return -1;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> g(3, vector<int>(3, -1));
        int turn = 1;
        for (int i = 0; i < moves.size(); i++) {
            auto &m = moves[i]; 
            g[m[0]][m[1]] = turn;
            turn ^= 1;
        }
        for (int i = 0; i < 3; i++) {
            int res = go(i, 0, {0, 1}, g);
            if (res != -1) {
                if (res == 1) return "A";
                if (res == 0) return "B";
            }
        }
        for (int j = 0; j < 3; j++) {
            int res = go(0, j, {1, 0}, g);
            if (res != -1) {
                if (res == 1) return "A";
                if (res == 0) return "B";
            }
        }
        {
            int res = go(0, 0, {1, 1}, g);
            if (res != -1) {
                if (res == 1) return "A";
                if (res == 0) return "B";
            }
        }
        {
            int res = go(0, 2, {1, -1}, g);
            if (res != -1) {
                if (res == 1) return "A";
                if (res == 0) return "B";
            }
        }
        
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) if (g[i][j] == -1)
                return "Pending";
        return "Draw";
    }
};