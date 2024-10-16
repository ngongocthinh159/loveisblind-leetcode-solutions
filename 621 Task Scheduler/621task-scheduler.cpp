class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> M;
        int mx = INT_MIN;
        int total = tasks.size();
        int sameMx = 0;
        for (int i = 0; i < tasks.size(); i++) {
            M[tasks[i]]++;
            mx = max(mx, M[tasks[i]]);
        }
        for (auto [key, cnt] : M) {
            if (cnt==mx) sameMx++;
        }
        int remain = total - sameMx*mx;
        int remainHole = (n - sameMx + 1)*(mx - 1);
        if (remain <= remainHole) return (mx - 1)*(n + 1) + sameMx;
        return total;        
    }
};