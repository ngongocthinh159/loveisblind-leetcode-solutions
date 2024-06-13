class Solution {
public:
    struct comparator {
        bool operator() (const vector<int>& v1, const vector<int> &v2) {
            if (v2[0] < v1[0]) return true;
            if (v2[0] == v1[0] && (v2[1] == 2 || v2[1] == 3) && (v1[1] == 0 || v1[1] == 1)) return true;
            return false;
        }
    };
    struct comparator2 {
        bool operator() (const vector<int> &v1, const vector<int> &v2) {
            if (v2[1] + v2[2] > v1[1] + v1[2]) return true;
            else if ((v2[1] + v2[2] == v1[1] + v1[2]) && v2[0] > v1[0]) return true;
            return false;
        }
    };
    int findCrossingTime(int n, int k, vector<vector<int>>& t) {
        priority_queue<vector<int>, vector<vector<int>>, comparator> pq;
        priority_queue<vector<int>, vector<vector<int>>, comparator2> right;
        priority_queue<vector<int>, vector<vector<int>>, comparator2> left;

        for (int i = 0; i < t.size(); i++) {
            left.push({i, t[i][2], t[i][0]});
        }

        
        int ans = INT_MIN;
        int take = 0;
        int come = 0;
        int passed = 0;
        int type, idx, time;
        unordered_set<int> S;
        int mx = INT_MIN;
        bool bridge_used = false;

        use_bridge_if_needed(right, left, pq, 0, t, passed, n, bridge_used);
        while (true) {
            auto cur = pq.top(); pq.pop();
            time = cur[0];
            type = cur[1];
            idx = cur[2];
            
            if (type == 0 || type == 1) {
                bridge_used = false;

                if (type == 0) { // brigde free due to left -> right
                    // push event of type 2
                    int e2_time;
                    if (take < n) {
                        e2_time = time + t[idx][1];
                        take++; S.insert(idx);
                    } else e2_time = time;

                    pq.push({e2_time, 2, idx});
                } else if (type == 1) { // bridge free due to right -> left
                    // push event of type 3
                    int e3_time;
                    
                    if (S.count(idx)) {
                        e3_time = time + t[idx][3];
                        come++;
                        S.erase(idx);
                        if (come == n) {
                            ans = time; break;
                        }
                    } else e3_time = time;

                    pq.push({e3_time, 3, idx});
                }

                // choose worker to use bridge
                use_bridge_if_needed(right, left, pq, time, t, passed, n, bridge_used);
            } else if (type == 2) { // done pickup in right
                right.push({idx, t[idx][2], t[idx][0]});
                use_bridge_if_needed(right, left, pq, time, t, passed, n, bridge_used);
            } else if (type == 3) { // done put left
                left.push({idx, t[idx][2], t[idx][0]});
                use_bridge_if_needed(right, left, pq, time, t, passed, n, bridge_used);
            }
        }
        return ans;
    }
    void use_bridge_if_needed(
    priority_queue<vector<int>, vector<vector<int>>, comparator2> &right, 
    priority_queue<vector<int>, vector<vector<int>>, comparator2> &left, 
    priority_queue<vector<int>, vector<vector<int>>, comparator> &pq,
    int time, 
    vector<vector<int>> &t,
    int &passed,
    int n,
    bool& bridge_used
    ) {
        // Process all events might happen at the same time before deciding to let any worker go through the bridge
        if (bridge_used) return;

        if (pq.size()) {
            auto tmp = pq.top();
            if (tmp[0] == time) return;
        }
        
        int use_idx = -1;
        bool right_to_left = true;
        if (right.size()) {
            auto tmp = right.top(); right.pop();
            use_idx = tmp[0];
        } else if (left.size() && passed != n) {
            auto tmp = left.top(); left.pop();
            use_idx = tmp[0];
            right_to_left = false;
        }

        // push new free bridge event after poping a worker
        if (use_idx != -1) {
            bridge_used = true;
            if (right_to_left) {
                pq.push({time + t[use_idx][2], 1, use_idx});
            }
            else {
                pq.push({time + t[use_idx][0], 0, use_idx});
                passed++;
            }
        }
    }
};