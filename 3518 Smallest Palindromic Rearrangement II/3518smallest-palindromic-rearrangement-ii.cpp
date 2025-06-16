#define ld long double
#define N 10005
ld logfact[N];
auto init = []{
    logfact[0] = 0;
    for (int i = 1; i < N; i++) 
        logfact[i] = logfact[i - 1] + log(i);
    return 0;
}();
class Solution {
public:
    int freq[26]{};
    int n;
    int len;
    const ld EPS = 1e-12;
    string smallestPalindrome(string s, int k) {
        n = s.size();
        for (auto c : s) freq[c - 'a']++;
        int cnt_odd = 0;
        char odd_c = 'a';
        for (int i = 0; i < 26; i++) if (freq[i]&1) cnt_odd++, odd_c = i + 'a';
        if ((n&1) && cnt_odd != 1) return "";
        if (!(n&1) && cnt_odd != 0) return "";

        for (int i = 0; i < 26; i++) freq[i] /= 2;
        len = n / 2;
        string res = "";
        
        while ((int) res.size() < len) {
            bool found = false;
            int chosen_len = res.size();
            for (int i = 0; i < 26; i++) if (freq[i]) {
                freq[i]--;
                ld choices = logfact[len - chosen_len - 1];
                for (int j = 0; j < 26; j++)
                    choices -= logfact[freq[j]];
                    
                if (choices - EPS > log(k) || fabs(choices - log(k)) < EPS) {
                    res += i + 'a';
                    found = true;
                    break;
                } else {
                    k -= round(exp(choices));
                    freq[i]++;
                }
            }
            if (!found) break;
        }

        if ((int) res.size() != len) return "";
        string t = res;
        reverse(t.begin(), t.end());
        if (n&1)
            res += odd_c;
        res += t;
        return res;
    }
};