class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> S;
        for (auto x : arr) {
            if (S.count(2*x)) return true;
            if (!(x&1) && S.count(x/2)) return true;
            S.insert(x);
        }
        return false;
    }
};