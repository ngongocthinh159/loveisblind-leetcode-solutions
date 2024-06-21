class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        int window = 0;
        for (int r = 0; r < minutes; r++) {
            if (grumpy[r]) window += customers[r];
            else sum += customers[r];
        }
        int mx = window;
        for (int r = minutes; r < n; r++) {
            if (grumpy[r]) window += customers[r];
            else sum += customers[r];
            if (grumpy[r - minutes]) window -= customers[r - minutes];
            mx = max(mx, window);
        }
        return mx + sum;
    }
};