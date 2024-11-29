class Solution {
public:
    int racecar(int target) {
        int r_bound = 3*target;
        int n = r_bound + 1;
        deque<pair<int,pair<int,int>>> q;
        q.push_back({0, {0, 0}});
        int msb = 32 - __builtin_clz(n) - 1;
        msb;
        vector<vector<vector<bool>>> dp(n,
            vector<vector<bool>>(msb,
                vector<bool>(2, false)));
        dp[0][0][0] = true;
        int level = 0;
        int ans = INT_MAX;
        while (q.size()) {
            int size = q.size();
            for (int cnt = 0; cnt < size; cnt++) {
                auto p = q.back(); q.pop_back();
                int pos = p.first;
                int speed_pow = p.second.first;
                int dir = p.second.second;
                {
                    int next_pos = pos + (1 << speed_pow) * (dir == 0 ? 1 : -1);
                    int next_speed_pow = speed_pow + 1;
                    if (next_pos >= 0 && next_pos < n && next_speed_pow < msb 
                            && !dp[next_pos][next_speed_pow][dir]) {
                                
                        dp[next_pos][next_speed_pow][dir] = true;
                        if (next_pos == target) return level + 1;
                        q.push_front({next_pos, {next_speed_pow, dir}});
                    }
                }

                {
                    int next_pos = pos;
                    int next_speed_pow = 0;
                    int oppo_dir = dir^0^1;
                    if (next_pos >= 0 && next_pos < n && next_speed_pow < msb 
                            && !dp[next_pos][next_speed_pow][oppo_dir]) {
                        
                        dp[next_pos][next_speed_pow][oppo_dir] = true;
                        if (next_pos == target) return level + 1;
                        q.push_front({next_pos, {next_speed_pow, oppo_dir}});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};