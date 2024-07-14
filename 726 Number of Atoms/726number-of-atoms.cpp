class Solution {
public:
    // unordered_map<string,int> M;
    unordered_map<int,int> openToClose;
    int n;
    string countOfAtoms(string s) {
        n = s.size();
        vector<int> v;
        int top;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') v.push_back(i);
            else if (s[i] == ')') {
                top = v.back(); v.pop_back();
                openToClose[top] = i;
            }
        }
        vector<pair<string,int>> v2;
        auto tmp = dfs(s, 0, n - 1);
        for (auto &[key, val] : tmp) {
            v2.push_back({key, val});
        }
        sort(v2.begin(), v2.end());
        string res = "";
        for (int i = 0; i < v2.size(); i++) {
            res += v2[i].first + (v2[i].second == 1 ? "" : to_string(v2[i].second));
        }
        return res;
    }
    unordered_map<string, int> dfs(string &s, int i, int j) {
        
        unordered_map<string, int> res;
        while (i <= j) {
            if (s[i] != '(') {
                int start = i;
                string element = "";
                element += s[i];
                int cnt = 1;

                while (i + 1 <= j && 'a' <= s[i + 1] && s[i + 1] <= 'z') {
                    i++;
                    element += s[i];
                }

                int tmp = 0;
                while (i + 1 <= j && '0' <= s[i + 1] && s[i + 1] <= '9') {
                    i++;
                    tmp = 10*tmp + (s[i] - '0');
                }

                if (tmp) {
                    cnt = tmp;
                }

                res[element] += cnt;

                i++;
            } else if (s[i] == '(') {
                int closeIdx = openToClose[i];
                auto res2 = dfs(s, i + 1, closeIdx - 1);           
                int cnt = 1;
                int k = closeIdx;

                int tmp = 0;
                while (k + 1 <= j && '0' <= s[k + 1] && s[k + 1] <= '9') {
                    tmp = 10*tmp + (s[k + 1] - '0');
                    k++;
                }

                if (tmp) {
                    cnt = tmp;
                }

                for (auto &[key, val] : res2) {
                    res[key] += val*cnt;
                }

                i = k + 1;
            }
        }
        return res;
    }
};