class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        int res = 0;
        for(const auto& [k,v] : map) {
            res += max(0, v*(v-1)/2);
        }
        return res;
    }
};