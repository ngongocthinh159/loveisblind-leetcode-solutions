class Solution {
public:
    int digit_len(int x) {
        if (x >= 1000) return 4;
        else if (x >= 100) return 3;
        else if (x >= 10) return 2;
        return 1;
    }
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        int tot = 0;
        int part = -1;
        for (int p = 1; p <= n; p++) {
            int len = digit_len(p);
            tot += len;
            int all_part_len = limit * p;
            // if (p == 14) {
            //     cout << len << ' ' << tot << ' ' << all_part_len << ' ' << n << '\n';
            //     cout << all_part_len - 3 * p - len * p - tot - n << '\n';
            // } // 126 - 3 * 14 - 2 * 14 - 19 - n
            int remain = all_part_len - 3 * p - len * p - tot - n;
            int will_get_len = limit - 3 - 2*len;
            if (0 <= remain && remain <= will_get_len) {
                part = p;
                break;
            }
        }
        if (part == -1) {
            // cout << "early" << '\n';
            return {};
        }
        vector<string> res;
        int part_len = digit_len(part);
        int i = 0;
        for (int p = 1; p <= part; p++) {
            int len = digit_len(p);
            int will_get_len = limit - 3 - len - part_len;
            string cur ="";
            while (i < n && will_get_len--) {
                cur += message[i++];
            }
            cur += '<';
            cur += to_string(p);
            cur += '/';
            cur += to_string(part);
            cur += '>';
            res.emplace_back(cur);
        }
        return res;
    }
};