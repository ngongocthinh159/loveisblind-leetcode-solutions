class Solution {
public:
    struct DSU {
        unordered_map<string,pair<string,double>> parent;
        unordered_map<string,int> size;
        DSU() {}
        void make_set(string &x) {
            parent[x] = {x, 1.0};
            size[x] = 1;
        } 
        pair<string,double> find(string &x) {
            if (parent[x].first == x) return parent[x];
            auto res = find(parent[x].first);
            return parent[x] = {res.first, 1.00 * parent[x].second * res.second};
        }
        bool same(string &a, string &b) {
            return find(a).first == find(b).first;
        }
        void unite(string &a, string &b, double ratio) {
            auto pa = find(a);
            auto pb = find(b);
            if (pa.first != pb.first) {
                if (size[pa.first] < size[pb.first]) {
                    swap(pa,pb);
                    ratio = 1/ratio;
                }
                size[pa.first] += size[pb.first];
                parent[pb.first] = {pa.first, pa.second / pb.second * ratio};
            } 
        }
    };
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        DSU dsu;
        unordered_set<string> S;
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            if (!S.count(u)) {S.insert(u); dsu.make_set(u);}
            if (!S.count(v)) {S.insert(v); dsu.make_set(v);}
            dsu.unite(u, v, 1/w);
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            string u = queries[i][0];
            string v = queries[i][1];
            if (S.count(u) && S.count(v) && dsu.same(u, v)) {
                auto pu = dsu.find(u);
                auto pv = dsu.find(v);
                res.push_back(pu.second/pv.second);
            } else {
                res.push_back(-1.0);
            }
        }
        return res;
    }
};