#define ll long long
class Solution {
public:
    struct comparator {
        bool operator() (const vector<int>&v1, const vector<int>&v2) {
            return v2[2] < v1[2];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comparator> pq;
        pq.push({0,0,nums1[0]+nums2[0]});
        vector<vector<int>> res;
        set<pair<int,int>> S;
        S.insert({0,0});
        while (res.size() < k) {
            auto p = pq.top(); pq.pop();
            int i = p[0];
            int j = p[1];
            res.push_back({nums1[i], nums2[j]});
            if (i+1<nums1.size() && !S.count({i+1,j})) {pq.push({i+1,j,nums1[i+1]+nums2[j]}); S.insert({i+1,j});}
            if (j+1<nums2.size() && !S.count({i,j+1})) {pq.push({i,j+1,nums1[i]+nums2[j+1]}); S.insert({i,j+1});}
        }
        
        return res;
    }
};