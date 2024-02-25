#define ll long long
const int mxN = 1e5;
vector<ll> spf;
bool ok = false;
void sieve() {
    spf.resize(mxN+1);
    for (ll i = 1; i <= mxN; i++) {
        spf[i] = i;
    }
    for (ll i = 2; i*i <= 1LL*mxN; i++) {
        if (spf[i] == i) {
            for (ll j = i*i; j <= 1LL*mxN; j+=i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
}
vector<vector<int>> prime_fact(int n) {
    vector<vector<int>> res;
    while (n!=1) {
        int fact = spf[n];
        int cnt = 0;
        while (n%fact==0) {
            cnt++;
            n/=fact;
        }
        res.push_back({fact,cnt});
    }
    return res;
}
struct DSU {
    vector<int> size;
    vector<int> parent;
    DSU(int n) {
        size.resize(n+1,-1);
        parent.resize(n+1,-1);
    }
    void make_set(int x) {
        size[x] = 1; parent[x] = x;
    }
    int find(int x) {
        if (x==parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool same(int a, int b) {return find(a)==find(b);}
    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra!=rb) {
            if (size[ra] < size[rb]) swap(ra,rb);
            size[ra]+=size[rb];
            parent[rb]=ra;
        }
    }
    bool not_have_set(int x) {return parent[x]==-1;}
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size()==1) return true;
        if (!ok) {sieve(); ok = true;}
        unordered_set<int> S;
        unordered_map<int,vector<int>> mp;
        int mx = *max_element(nums.begin(),nums.end());
        DSU dsu(mx);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]==1) return false;
            if (S.count(nums[i])) continue;
            
            S.insert(nums[i]);
            dsu.make_set(nums[i]);
            auto res = prime_fact(nums[i]);
            for (auto &v : res) {
                int fact = v[0];
                if (dsu.not_have_set(fact)) {dsu.make_set(fact); S.insert(fact);}
                dsu.unite(nums[i],fact);
            }
        }
        int first = nums[0];
        for (auto i : S) {
            if (!dsu.same(first,i)) return false;
        }
        return true;
    }
};