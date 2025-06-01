int bestEnergy[25][25][1 << 10];
int posToId[25][25];
const vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};    
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        const int IINF = 1e9;
        int xs, ys, L = 0;
        int id = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') xs = i, ys = j;
                if (classroom[i][j] == 'L') L++, posToId[i][j] = id++;
            }
        if (L == 0) return 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int p = 0; p < (1 << L); p++)
                    bestEnergy[i][j][p] = -1;
        bestEnergy[xs][ys][0] = energy;
        deque<pair<pair<int,int>,int>> q;
        q.push_front({{xs, ys}, 0});
        int level = 0, fmask = (1 << L) - 1;
        while (q.size()) {
            for (int sz = q.size(); sz; sz--) {
                auto p = q.back();
                q.pop_back();
                int i = p.first.first;
                int j = p.first.second;
                int mask = p.second;
                if (bestEnergy[i][j][mask]) {
                    for (auto &move : moves) {
                        int I = i + move.first;
                        int J = j + move.second;
                        if (0 <= I && I < n && 0 <= J && J < m && classroom[I][J] != 'X') {
                            if (classroom[I][J] == 'L') {
                                int nmask = mask | (1 << posToId[I][J]);
                                if (bestEnergy[I][J][nmask] < bestEnergy[i][j][mask] - 1) {
                                    bestEnergy[I][J][nmask] = bestEnergy[i][j][mask] - 1;
                                    q.push_front({{I, J}, nmask});
                                    if (nmask == fmask) {
                                        return level + 1;
                                    }
                                }
                            } else if (classroom[I][J] == 'R')  {
                                if (bestEnergy[I][J][mask] < energy) {
                                    bestEnergy[I][J][mask] = energy;
                                    q.push_front({{I, J}, mask});
                                }
                            } else {
                                if (bestEnergy[I][J][mask] < bestEnergy[i][j][mask] - 1) {
                                    bestEnergy[I][J][mask] = bestEnergy[i][j][mask] - 1;
                                    q.push_front({{I, J}, mask});
                                }
                            }
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};