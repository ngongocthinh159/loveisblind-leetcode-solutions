class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int diag = -1, area = -1;
        for (int i = 0; i < n; i++) {
            int a = dimensions[i][0];
            int b = dimensions[i][1];
            int d = a * a + b * b;
            if (diag < d) {
                diag = d;
                area = a * b;
            } else if (diag == d && area < a * b) 
                area = a * b;
        }
        return area;
    }
};