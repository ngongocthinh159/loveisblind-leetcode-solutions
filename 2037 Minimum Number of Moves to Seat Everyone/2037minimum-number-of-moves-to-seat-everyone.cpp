class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> cnt1(101, 0);
        vector<int> cnt2(101, 0);
        for (int i = 0; i < seats.size(); i++) {
            cnt1[seats[i]]++;
            cnt2[students[i]]++;
        }
        int i = 1, j = 1, take, ans = 0;
        while (i <= 100 && j <= 100) {
            if (cnt1[i] == 0) i++;
            else if (cnt2[j] == 0) j++;
            else {
                take = min(cnt1[i], cnt2[j]);
                ans += take*abs(i - j);
                cnt1[i] -= take; cnt2[j] -= take;
            }
        }
        return ans;
    }
};