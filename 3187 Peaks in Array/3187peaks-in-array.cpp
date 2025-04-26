struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        FenwickTree tree(n);
        vector<int> peak(n);
        for (int i = 1; i < n - 1; i++) if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            tree.add(i, 1), peak[i] = 1;
        vector<int> ans;
        pair<int,int> buf[3];
        for (auto &q : queries) {
            if (q[0] == 1) {
                int l = q[1] + 1;
                int r = q[2] - 1;
                if (l > r)
                    ans.push_back(0);
                else
                    ans.push_back(tree.sum(l, r));
            } else {
                int top = 0;
                nums[q[1]] = q[2];
                for (int i = q[1] - 1; i <= q[1] + 1; i++) {
                    if (0 <= i && i < n) {
                        int cur = 0;
                        if (i - 1 >= 0 && i + 1 < n 
                            && nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                            cur = 1;
                        buf[top++] = {cur, i};
                    }
                }

                for (int i = 0; i < top; i++) {
                    tree.add(buf[i].second, buf[i].first - peak[buf[i].second]);
                    peak[buf[i].second] = buf[i].first;
                }
            }
        }
        return ans;
    }
};