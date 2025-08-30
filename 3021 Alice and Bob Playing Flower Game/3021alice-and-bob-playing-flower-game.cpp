class Solution {
public:
    /*
        Can always proof that:
            1. odd, ood
                => first go lose

            2. even, even
                => first go lose
            
            3. odd even or even or
                => first player can always bring to case 1 => first player always win
    */
    long long flowerGame(int n, int m) {
        long long ans = 0;
        ans += 1LL * (n / 2) * ((m + 1) / 2);
        ans += 1LL * ((n + 1) / 2) * (m / 2);
        return ans;
    }
};