class Solution {
public:
    /** How do we know if a number x has k numbers less than or equal to it?
    
        We obviously can't check by generating the table since that would take O(m*n) time. But we can do better by looking at how numbers appear in the table. In each row, the numbers we get, are of the form - [i, 2*i, 3*i,...,k*i,...n*i]. Using this observation, we can iterate over each row and count number of elements-N in that row that are less than or equal to x:**/
    
    // Count if the current choosen number (mid) have enough k - 1 number before it
    // => If yes, this number can be the k-th smallest element => Keep binary search for samller number
    bool isEnoughNumberBeforeMid(int num, int m, int n, int k) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(n, num / i);
            
            if (count >= k) return true;
        }
        return false;
    } 
    
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (isEnoughNumberBeforeMid(mid, m, n, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return r;
    }
};