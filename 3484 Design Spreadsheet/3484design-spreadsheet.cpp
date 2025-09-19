class Spreadsheet {
public:
    vector<vector<int>> grid;
    int n, m;
    Spreadsheet(int rows) {
        n = rows;
        m = 26;
        grid.assign(n, vector<int>(m));
    }
    
    pair<int,int> cellToRowCol(string &cell) {
        pair<int,int> res;
        res.second = cell[0] - 'A';
        int i = 1;
        while (i < cell.size()) {
            res.first = 10 * res.first + (cell[i++] - '0');
        }
        --res.first;
        return res;
    }
    void setCell(string cell, int value) {
        auto p = cellToRowCol(cell);
        grid[p.first][p.second] = value;
    }
    
    void resetCell(string cell) {
        auto p = cellToRowCol(cell);
        grid[p.first][p.second] = 0;
    }
    
    int getVal(string &s) {
        if ('0' <= s[0] && s[0] <= '9') {
            int res = 0, i = 0;
            while (i < s.size()) res = 10 * res + s[i++] - '0';
            return res;
        } else {
            auto p = cellToRowCol(s);
            return grid[p.first][p.second];
        }
    }
    int getValue(string formula) {
        int i = 1;
        string s1 = "", s2 = "";
        while (formula[i] != '+') s1 += formula[i++];
        i++;
        while (i < formula.size()) s2 += formula[i++];
        return getVal(s1) + getVal(s2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */