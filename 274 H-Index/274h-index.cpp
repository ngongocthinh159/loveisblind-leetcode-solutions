class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = -1;
        for (int i = 0; i < citations.size(); i++) {
            res = max(res, min(citations[i], (int) citations.size()-i));
        }

        return res;
    }
};