class Solution {
public:
    bool f = false;
    int dfs(int sx, int sy, int tx, int ty) {
        if (tx > ty) return dfs(sy, sx, ty, tx);
        if (tx == sx && ty == sy) {
            f = true;
            return 0;
        }
        if (tx == ty) {
            if (!(sx == 0 || sy == 0))
                return -1;
            if (sx == 0 && sy == 0)
                return -1;
            if (sy == 0) return dfs(sy, sx, ty, tx);
            if (sy > tx) return -1;
            if (sy < tx) return 1 + dfs(sx, 2 * sy, tx, ty);
            f = true;
            return 1;
        }
        if (tx * 2 == ty) return 1 + dfs(sx, sy, tx, tx);
        if (tx * 2 < ty) {
            if (ty % 2 != 0) return -1;
            return 1 + dfs(sx, sy, tx, ty / 2);
        } 
        // tx * 2 > ty
        return 1 + dfs(sx, sy, tx, ty - tx);
    }
    int minMoves(int sx, int sy, int tx, int ty) {
        int res = dfs(sx, sy, tx, ty);
        if (f)
            return res;
        else
            return -1;
    }
};