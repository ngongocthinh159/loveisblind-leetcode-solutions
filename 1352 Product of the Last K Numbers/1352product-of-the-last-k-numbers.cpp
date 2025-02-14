class ProductOfNumbers {
public:
    vector<pair<int,int>> v;
    int last_zero = -1;
    ProductOfNumbers() {
        v.push_back({1, 1});
    }
    
    void add(int num) {
        if (v.back().first == 0) v.push_back({num, num});
        else v.push_back({num * v.back().first, num});
        if (num == 0) last_zero = v.size() - 1;
    }
    
    int getProduct(int k) {
        int l = v.size() - k;
        if (l <= last_zero) return 0;
        int r = v.size() - 1;
        return v[r].first / v[l].first * v[l].second;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */