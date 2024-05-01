class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<char> q;
        int rad = 0, dir = 0;
        for (int i = 0; i < senate.size(); i++) {
            q.push_back(senate[i]);
            if (senate[i] == 'R') rad++;
            else dir++;
        }
        if (rad == 0) return "Dire";
        if (dir == 0) return "Radiant";
        int del_rad = 0, del_dir = 0;
        while (true) {
            char c = q.front(); q.pop_front();
            if (c == 'R') {
                if (del_rad > 0) {
                    del_rad--;
                } else {
                    dir--;
                    del_dir++;
                    q.push_back(c);
                }
            } else {
                if (del_dir > 0) {
                    del_dir--;
                } else {
                    rad--;
                    del_rad++;
                    q.push_back(c);
                }
            }
            if (rad == 0) return "Dire";
            if (dir == 0) return "Radiant";
        }
        return "";
    }
};