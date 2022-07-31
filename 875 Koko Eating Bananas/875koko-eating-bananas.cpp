class Solution {
public:
    bool feasible(int speed, vector<int>& piles, int h) {
        int hour_need = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] % speed == 0) {
                hour_need += piles[i] / speed;
            } else {
                hour_need += piles[i] / speed + 1;
            }
            
            if (hour_need > h) return false;
        }
        
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = -1;
        for (int i = 0; i < piles.size(); i++) {
            if (max < piles[i]) max = piles[i];
        }
        
        int l = 1, r = max;
        while (l < r) {
            int m = l + (r - l) / 2;
            
            if (feasible(m, piles, h)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        return r;
    }
};