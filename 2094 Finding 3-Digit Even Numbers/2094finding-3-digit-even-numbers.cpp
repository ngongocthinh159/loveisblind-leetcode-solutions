class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10]{}, f[10]{};
        vector<int> res;
        for (auto d : digits) freq[d]++;
        for (int i = 100; i <= 999; i += 2) {
            int x = i;
            bool ok = true;
            for (int d = 0; d <= 9; d++) f[d] = 0;
            for (int j = 1; j <= 3; j++) f[x % 10]++, x /= 10;
            for (int d = 0; d <= 9; d++) if (f[d] > freq[d]) ok = false;
            if (ok)
                res.push_back(i);
        }
        return res;
    }
};