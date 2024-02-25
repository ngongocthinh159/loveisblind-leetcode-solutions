class Solution {
public:
    struct comparator {
        bool operator() (const vector<int>&v1, const vector<int>&v2) const {
            return v2[2] < v1[2];
        }
    };
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<vector<int>,vector<vector<int>>,comparator> pq;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            pq.push({i,i+1,abs(nums[i]-nums[i+1])});
        }
        int cnt = 0, ans;
        while (true) {
            cnt++;
            auto v = pq.top(); pq.pop();
            int i = v[0];
            int j = v[1];
            if (j+1<nums.size()) pq.push({i,j+1,abs(nums[i]-nums[j+1])});
            if (cnt==k) {
                ans = v[2]; break;
            }
        }
        return ans;
    }
};