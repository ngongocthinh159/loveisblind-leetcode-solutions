class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one = 0, zero = 0;
        for (auto x : students) {
            if (x==1 )one++;
            else zero++;
        }
        int cnt = 0;
        for (auto x : sandwiches) {
            cnt++;
            if (x==1 && one > 0) one--;
            else if (x==0 && zero > 0) zero--;
            else {cnt--; break;}
        }
        return sandwiches.size() - cnt;
    }
};