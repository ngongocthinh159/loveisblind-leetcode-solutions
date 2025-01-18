#define MAX 2
#define MAX_BIT 19
struct Node {
    vector<Node*> child;
    int cnt = 0;
    int sub_cnt = 0;
    Node() {
        child.assign(MAX, NULL);
    }
};
class Solution {
public:
    void dfs(Node* root) {
        if (!root) return;
        root->sub_cnt = root->cnt;
        for (int i = 0; i < MAX; i++) {
            dfs(root->child[i]);
            if (root->child[i]) root->sub_cnt += root->child[i]->sub_cnt;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        Node* root = new Node;
        int idx;
        int n = nums.size();
        k = n - k + 1;
        for (auto x : nums) {
            auto p = root;
            for (int bit = MAX_BIT; bit >= 0; bit--) {
                idx = (x >> bit) & 1;
                if (!p->child[idx]) p->child[idx] = new Node;
                p = p->child[idx];
            }
            p->cnt++;
        }
        dfs(root);
        auto p = root;
        int res = 0;
        for (int bit = MAX_BIT; bit >= 0; bit--) {
            if (p->child[0] && p->child[1]) {
                if (p->child[0]->sub_cnt >= k) p = p->child[0];
                else {
                    res |= (1 << bit);
                    k -= p->child[0]->sub_cnt;
                    p = p->child[1];
                }
            } else if (p->child[0]) p = p->child[0];
            else {
                res |= (1 << bit);
                p = p->child[1];
            }
        }
        return res;
    }
};