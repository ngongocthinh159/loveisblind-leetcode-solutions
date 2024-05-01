class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int first_pos_idx = -1;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {first_pos_idx = i; break;}
        }
        if (first_pos_idx == -1) return asteroids;
        vector<int> res;
        for (int i = 0; i < first_pos_idx; i++) {
            res.push_back(asteroids[i]);
        }
        stack<int> S;
        for (int i = first_pos_idx; i < n; i++) {
            if (asteroids[i] > 0) {
                S.push(asteroids[i]);
            } else {
                bool exploded = false;
                while (S.size()) {
                    if (S.top() > abs(asteroids[i])) {exploded = true; break;}
                    else if (S.top() == abs(asteroids[i])) {exploded = true; S.pop(); break;}
                    else S.pop();
                }
                if (!exploded) res.push_back(asteroids[i]);      
            }
        }
        int l = res.size();
        while (S.size()) {res.push_back(S.top()); S.pop();}
        reverse(res.begin() + l, res.end());
        return res;
    }
};