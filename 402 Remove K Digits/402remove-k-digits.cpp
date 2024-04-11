class Solution {
public:
    string removeKdigits(string num, int k) {
        num;
        vector<int> v;
        deque<int> q;
        int r = 0;
        for (int i = 0; i < num.size() && k > 0;) {
            int mxIdx = min(i + k, (int) num.size() - 1);
            while (r <= mxIdx) {
                while (q.size() && num[r] < num[q.back()]) q.pop_back();
                q.push_back(r);
                r++;
            }
            while (q.size() && !(i + 1 <= q.front() && q.front() <= mxIdx)) q.pop_front();
            if (q.size()) {
                int mnIdx = q.front();
                if (num[mnIdx] < num[i]) {
                    for (int j = i; j < mnIdx; j++) {
                        v.push_back(j);
                    }
                    k -= (mnIdx - i);
                    i = mnIdx;
                } else i++;
            } else break;
        }

        string res = "";
        int i = 0, j = 0;
        while (i < num.size() && j < v.size()) {
            if (i < v[j]) res += num[i++];
            else if (i == v[j]) {
                i++; j++;
            }
        }
        while (i < num.size()) res += num[i++];
        if (k >= res.size()) return "0";
        else {
            i = 0;
            while (i < res.size() && res[i] == '0') i++;
            string res2 = res.substr(i);
            while (k > 0 && res2.size()) {
                res2.pop_back(); k--;
            }
            if (res2 == "") res2 = "0";
            return res2;
        }
    }
};