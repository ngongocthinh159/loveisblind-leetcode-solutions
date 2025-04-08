#define ll long long
class Solution {
public:
    const ll LINF = 1e18;
    
    // bool check(int x, vector<int>& nums) {
    //     set<pair<int,ll>> ind = indices;
    //     set<pair<ll,pair<int,int>>> s = S;
        
    //     int prev = -1;
    //     for (auto &p : ind) {
    //         if (p.second < prev) 
    //             return false;
    //         prev = p.second;
    //     }
    //     return true;
    // }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        set<pair<int,ll>> ind;
        set<pair<ll,pair<int,int>>> s;
        int pairs = 0;
        for (int i = 0; i < n; i++) {
            ind.insert({i, nums[i]});
            if (i - 1 >= 0 && nums[i] < nums[i - 1]) pairs++;
            if (i + 1 < n) s.insert({nums[i] + nums[i + 1], {i, i + 1}});
        } 
        if (!pairs) return 0;
        int cnt = 1;
        for (; cnt <= n - 1; cnt++) {
            auto p = *s.begin();
            s.erase(s.begin());
            int i = p.second.first;
            int j = p.second.second;
            auto it_i = ind.lower_bound({i, -LINF});
            auto it_j = ind.lower_bound({j, -LINF});
            auto p_i = *it_i;
            auto p_j = *it_j;
            if (p_i.second > p_j.second) 
                pairs--;
            // cout << p_i.first << " " << p_j.first << " " << pairs << "\n";
            if (it_i != ind.begin()) {
                auto it = prev(it_i);
                auto _p = *it;
                s.erase({p_i.second + _p.second, {_p.first, i}});
                s.insert({p.first + _p.second, {_p.first, i}});
                if (_p.second > p_i.second)
                    pairs--;
                if (_p.second > p.first)
                    pairs++;
            }
            if (it_j != ind.end()) {
                auto it = next(it_j);
                if (it != ind.end()) {
                    auto _p = *it;
                    s.erase({p_j.second + _p.second, {j, _p.first}});
                    s.insert({p.first + _p.second, {i, _p.first}});
                    if (_p.second < p_j.second)
                        pairs--;
                    if (_p.second < p.first)
                        pairs++;
                }
            }
            if (!pairs)
                break;

            ind.erase(p_i);
            ind.erase(p_j);
            ind.insert({i, p.first});
        }
        return cnt;
    }
};