class Solution {
public:
    long long cur;
    bool largerEqualK(int even_cnt, int odd_cnt, bool both_start, long long k) {
        if (even_cnt == 0 && odd_cnt == 0) {
            cur = 0;
            return k == 1;
        }
        cur = both_start ? 2 : 1;
        for (int i = 1; i <= even_cnt; i++) {
            if (cur * i >= k) return true;
            cur = cur * i;
        }
        for (int i = 1; i <= odd_cnt; i++) {
            if (cur * i >= k) return true;
            cur = cur * i;
        }
        return false;
    }
    vector<int> permute(int n, long long k) {
        set<int> odd, even, all;
        int odd_cnt = (n + 1)/2, even_cnt = n/2;
        for (int i = 1; i <= n; i++) {
            if (i&1) 
                odd.insert(i);
            else
                even.insert(i);
            all.insert(i);
        }
        vector<int> res;
        if (!largerEqualK(even_cnt, odd_cnt, 1, k)) return res;
        bool pick_odd = true;
        for (int i = 0; i < n; i++) {
            if (i == 0 && odd_cnt == even_cnt) {
                for (auto x : all) {
                    set<int> &list = (x&1) ? odd : even;
                    int &cnt = (x&1) ? odd_cnt : even_cnt;

                    cnt--;
                    if (!largerEqualK(even_cnt, odd_cnt, 0, k)) {
                        k -= cur;
                        cnt++;
                    } else {
                        list.erase(x);
                        res.push_back(x);
                        pick_odd = !(x&1);
                        break;
                    }
                }
            } else {
                set<int>& list = pick_odd ? odd : even;
                int &cnt = pick_odd ? odd_cnt : even_cnt;
                for (auto x : list) {
                    
                    cnt--;
                    if (!largerEqualK(even_cnt, odd_cnt, 0, k)) {
                        k -= cur;
                        cnt++;
                    } else {
                        res.push_back(x);
                        list.erase(x);
                        break;
                    }
                }
                pick_odd ^= 1;
            }
        }
        return res;
    }
};