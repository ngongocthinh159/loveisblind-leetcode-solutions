class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for (auto num : apple) {
            sum += num;
        }
        sort(capacity.begin(),capacity.end(), greater<int>());
        int cur = 0;
        int i = 0, cnt= 0;
        while (cur < sum) {
            cnt++;
            cur += capacity[i++];
        }
        return cnt;
    }
};