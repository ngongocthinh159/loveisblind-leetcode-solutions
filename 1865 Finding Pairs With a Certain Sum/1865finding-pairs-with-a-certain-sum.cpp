class FindSumPairs {
public:
    unordered_map<long long,int> freq2;
    vector<int> nums1, nums2;
    FindSumPairs(vector<int>& _nums1, vector<int>& _nums2) {
        this->nums1 = _nums1;
        this->nums2 = _nums2;
        for (auto x : nums2) freq2[x]++;
    }
    
    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] += val; 
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (auto x : nums1) {
            res += freq2[tot - x];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */