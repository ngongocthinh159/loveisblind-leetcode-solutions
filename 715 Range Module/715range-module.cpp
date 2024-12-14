class RangeModule {
public:
    set<pair<int,int>> S;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        right--;
        auto l = S.upper_bound({left, INT_MAX});
        auto r = S.upper_bound({right + 1, INT_MAX});
        if (l != S.begin()) {
            l--;
            if (l->second + 1 < left) l++;
        }
        if (l != r) {
            left = min(l->first, left);
            right = max((--r)->second, right);
            S.erase(l, ++r);
        }
        S.insert({left, right});

        // cout << "Add range: [" << left << ", " << right << "]\n";
        // for (auto p : S) cout << p.first << " " << p.second << "\n";
        // cout << "\n";
    }
    
    bool overlap(pair<int,int>a,pair<int,int>b){
        if(a.first>b.second || a.second<b.first) return false;
        return true;
    }
    bool queryRange(int left, int right) {
        right--;
        bool res;
        auto l = S.upper_bound({left, INT_MAX});
        if (l == S.begin() || (--l)->second < right) res = false;
        else res = true;

        // cout << "Query range: [" << left << ", " << right << "]\n";
        // for (auto p : S) cout << p.first << " " << p.second << "\n";
        // cout << "res: " << res << "\n";
        // cout << "\n";
        return res;

        // r--;
        
        // for(auto i:S){
        //     if(overlap(i,{l,r})){
        //         if(i.first<=l && i.second>=r) return true;
        //         if(i.first>l) r= i.first-1;
        //         if(r>i.second) l = i.second+1;
        //     }
            
        // }
        // return l<=0 || r<=0;
    }
    
    void removeRange(int left, int right) {
        right--;
        auto l = S.upper_bound({left, INT_MAX});
        auto r = S.upper_bound({right, INT_MAX});
        if (l != S.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l != r) {
            r--;

            pair<int,int> r1 = {-1, -1};
            pair<int,int> r2 = {-1, -1};

            if (l->first < left) r1 = {l->first, left - 1};
            if (r->second > right) r2 = {right + 1, r->second};

            S.erase(l, ++r);

            if (r1.first != -1) S.insert(r1);
            if (r2.first != -1) S.insert(r2);
        }

        // cout << "Remove range: [" << left << ", " << right << "]\n";
        // for (auto p : S) cout << p.first << " " << p.second << "\n";
        // cout << "\n";
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */