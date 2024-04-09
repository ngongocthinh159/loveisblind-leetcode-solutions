class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans++;
            tickets[i]--;
        }
        for (int i = 0; i < tickets.size(); i++) {
            ans += min(tickets[i], tickets[k]);
        }
        return ans;
    }
};