class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long finish_time = 0;
        long long waiting_times = 0;
        int n = customers.size();
        long long start_time, cur_finish_time;
        for (int i = 0; i < n; i++) {
            start_time = max(finish_time, 1LL*customers[i][0]);
            
            finish_time = start_time + customers[i][1];

            waiting_times += finish_time - customers[i][0];
        }
        return 1.00*waiting_times/n;
    }
};