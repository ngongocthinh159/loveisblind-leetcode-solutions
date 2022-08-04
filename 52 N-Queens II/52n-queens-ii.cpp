class Solution {
public:
    bool savePlace(int row, int col, vector<pair<int,int>> placedQ) {
        for (auto lastQ : placedQ) {
            if (lastQ.first == row || lastQ.second == col || abs(lastQ.first - row) == abs(lastQ.second - col)) return false;
        }
        return true;
    }
    
    void solve(int n, int count, int &res, vector<pair<int,int>> placedQ) {
        if (count == n) {
            res++;
            return;
        }
        
        // For each queen choose an appropriate column
        for (int i = 0; i < n; i++) {
            if (savePlace(count, i, placedQ)) {
                placedQ.push_back(make_pair(count, i));
                
                solve(n, count + 1, res, placedQ);
                placedQ.pop_back();
            }
        }
        
        return;
    }
    
    int totalNQueens(int n) {
        int res = 0;
        vector<pair<int,int>> placedQ;
        solve(n, 0, res, placedQ);
        return res;
    }
};