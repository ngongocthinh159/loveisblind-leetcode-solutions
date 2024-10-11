class Solution {
public:
    struct comparator {
        bool operator() (int a, int b) {
            if (b < a) return true;
            return false;
        }
    };
    struct comparator2 {
        bool operator() (pair<int,int> &p1, pair<int,int> &p2) {
            if (p2.first < p1.first) return true;
            return false;
        }
    };
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int maxChair = 0;
        priority_queue<int, vector<int>, comparator> minChair;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator2> leaveFriends;
        
        unordered_map<int,int> arrivalToIdx;
        for (int i = 0; i < times.size(); i++) {
            arrivalToIdx[times[i][0]] = i;
        }

        sort(times.begin(), times.end());
        int i = 0;
        while (true) {
            while (leaveFriends.size() && leaveFriends.top().first <= times[i][0]) {
                auto p = leaveFriends.top();
                leaveFriends.pop();
                minChair.push(p.second);
            }

            int assignedChair;
            if (minChair.size()) {
                assignedChair = minChair.top();
                minChair.pop();
            } else assignedChair = maxChair++;

            if (arrivalToIdx[times[i][0]] == targetFriend) {
                // cout << i << " " << arrivalToIdx[times[i][0]] << " " << times[i][0] << "\n";
                return assignedChair;
            }

            leaveFriends.push({times[i][1], assignedChair});

            i++;
        }
        return -1;
    }
};