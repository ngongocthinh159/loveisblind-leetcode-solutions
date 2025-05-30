class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx > ty) return reachingPoints(sy, sx, ty, tx);
        if (sx > tx || sy > ty) return false;
        if (sx == tx && sy == ty) return true;

        int nxt = ty % tx;
        if (nxt >= sy)
            return reachingPoints(sx, sy, tx, nxt);
        else 
            return (ty - sy) % tx == 0 && tx == sx;
    }
};