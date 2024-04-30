#define ll long long
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int mask = 0, idx;
        ll ans = 0;
        unordered_map<int, ll> M;
        M[0] = 1;
        for (int i = 0; i < word.size(); i++) {
            idx = word[i] - 'a';
            mask = mask ^ (1 << idx);
            
            for (int j = 0; j < 10; j++) {
                int target = (1 << j);
                ans += M[mask^target];
            }
            ans += M[mask];

            M[mask]++;
        }
        return ans;
    }
};