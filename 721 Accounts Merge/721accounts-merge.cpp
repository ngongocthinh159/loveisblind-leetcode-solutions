using namespace std;
template<typename A, typename B>
concept Container = requires(A a)
{
    {
    std::default_initializable<A> &&
    std::random_access_iterator<A> && requires { A{}; } && requires { ::new A; }
    };
    { std::regular<B> };
};

template<typename T>
concept Hashable = requires(T a)
{
    { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
    { std::regular<T> };
};

template<Hashable T, Container<T> F>
class DSU {
private:
    F anc;
    unordered_map<T, int> size;
public:
    DSU() {
        anc = F();
        size = unordered_map<T, int>();
    }

    void make_set(T a) {
        anc[a] = a;
        size[a] = 1;
    }

    T find_set(T a) {
        if (a == anc[a])
            return a;

        return anc[a] = find_set(anc[a]);
    }

    void merge(T a, T b) {
        T sa = find_set(a);
        T sb = find_set(b);
        if (sa != sb) {
            if (size[sa] < size[sb])
                swap(sa, sb);
            anc[sb] = sa;
            size[sa] += size[sb];
        }
    }
};

class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU<int, unordered_map<int,int>> dsu;
        int id = 0;
        unordered_map<string, int> M;
        for (int i = 0; i < accounts.size(); i++) {
            int accId = id++;
            dsu.make_set(accId);
            for (int j = 1; j < accounts[i].size(); j++) {
                if (M.count(accounts[i][j])) dsu.merge(M[accounts[i][j]], accId);
                else M[accounts[i][j]] = accId;
            }
        }
        unordered_map<int, vector<string>> M2;
        for (auto &[email, orgId] : M) {
            int parentId = dsu.find_set(orgId);
            M2[parentId].push_back(email);
        }
        vector<vector<string>> res;
        for (auto &[key,val] : M2) {
            vector<string> v;
            v.push_back(accounts[key][0]);
            for (auto &email: val) {
                v.push_back(email);
            }
            sort(v.begin() + 1, v.end());
            res.push_back(v);
        }
        return res;
    }
};