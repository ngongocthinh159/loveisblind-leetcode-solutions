class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = -1, cnt = 0;
        long long sum = 0;
        for (auto x : milestones) mx = max(mx, x), sum += x;
        for (auto x : milestones) if (x == mx) cnt++;
        if (cnt >= 2) return sum;
        long long sum2 = 0;
        for (auto x : milestones) if (x != mx) sum2 += x;
        if (sum2 >= mx) return sum;
        return sum2*2 + 1;
    }
};