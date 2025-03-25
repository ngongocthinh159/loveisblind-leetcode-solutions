#define MAX 100005

int tmp[MAX], cnt = -1;
class Solution {
public:
    bool check(vector<pair<int,int>> &v) {
        sort(v.begin(), v.end());
        priority_queue<int> q;
        int n = v.size();
        int cut = 0;
        int valid = 0;
        for (int i = 0; i < n;) {
            int start = v[i].first;
            while (q.size() && q.top() <= start) {
                q.pop();
                cut--;
            }

            if (cut == 0) valid++;

            cnt = -1;
            while (i < n && v[i].first == start) {
                tmp[++cnt] = v[i].second;
                i++;
                cut++;
            }
            
            for (int j = 0; j <= cnt; j++) q.push(tmp[j]);
        }
        return valid >= 3;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> xs;
        vector<pair<int,int>> ys;
        for (auto &v : rectangles) {
            xs.push_back({v[0], v[2]});
            ys.push_back({v[1], v[3]});
        }
        return check(xs) || check(ys);
    }
};