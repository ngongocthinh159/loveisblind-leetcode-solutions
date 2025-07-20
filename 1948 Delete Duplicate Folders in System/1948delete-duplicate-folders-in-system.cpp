#define ll long long
#define N 100005
ll basepow[N];
const int base = 32;
const int MOD = 1e9 + 7;
auto init = []{
    basepow[0] = 1;
    for (int i = 1; i < N; i++) basepow[i] = basepow[i - 1] * base % MOD;
    return false;
}();
class Solution {
public:
    struct Node {
        ll subhash = 0;
        ll chash = 0;
        int subsz = 0;
        map<string,Node*> child;
    };
    unordered_map<ll,int> chashFreq;
    vector<vector<string>> res;
    vector<string> path;
    void add(ll &x, ll y) {
        x += y;
        if (x >= y) x -= MOD;
    }
    ll getHash(const string &s) {
        ll res = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            res += (s[i] - 'a' + 1) * basepow[i] % MOD;
            if (res >= MOD) res -= MOD;
        }
        return res;
    }
    void dfs(Node *root, const string &s) {
        ll chash = 0;
        for (auto &[sv, v] : root->child) {
            dfs(v, sv);

            add(chash, 131 * basepow[root->subsz] % MOD);
            add(chash, v->subhash * basepow[root->subsz] % MOD);

            root->subsz += v->subsz;
        }

        root->chash = chash;
        if (root->child.size())
            chashFreq[root->chash]++;
        
        add(chash, getHash(s) * basepow[root->subsz] % MOD);
        root->subhash = chash;
        root->subsz += 1;
    }
    void dfs2(Node* root, const string &s) {
        if (chashFreq[root->chash] >= 2 && root->child.size() != 0)
            return;
        if (path.size())
            res.push_back(path);
        for (auto &[sv, v] : root->child) {
            path.push_back(sv);
            dfs2(v, sv);
            path.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();        
        for (auto &path : paths) {
            Node* p = root;
            for (auto &u : path) {
                if (!p->child.count(u)) p->child[u] = new Node;
                p = p->child[u];
            }
        }
        dfs(root, "");
        dfs2(root, "");
        return res;
    }
};