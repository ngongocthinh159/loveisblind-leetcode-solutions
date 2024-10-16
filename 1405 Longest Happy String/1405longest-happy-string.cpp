class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        map<int,char> M;
        int idx = 2;
        int mx[3];
        char mxc[3];
        for (auto &[key, val] : M) {
            mx[idx] = key;
            mxc[idx] = val;
            idx--;
        }
        char prevprev = '$';
        char prev = '#';
        string res = "";
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        while (true) {
            auto p = pq.top(); pq.pop();
            int cnt = p.first;
            int curC = p.second;
            if (cnt == 0) break;
            
            if (curC == prev && prev == prevprev) {
                auto p2 = pq.top(); pq.pop();
                pq.push({cnt, curC}); // push top
                cnt = p2.first;
                curC = p2.second;
            }
            if (cnt == 0) break;

            cnt--;
            res += curC;
            pq.push({cnt, curC});

            prevprev = prev;
            prev = curC;
        }
        return res;
    }
};