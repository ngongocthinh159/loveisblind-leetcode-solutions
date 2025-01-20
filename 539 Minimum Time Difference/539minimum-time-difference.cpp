class Solution {
public:
    int toInt(string &s) {
        int hours = stoi(s.substr(0, 2));
        int minutes = stoi(s.substr(3, 2));
        return hours*60 + minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (timePoints[i] == "00:00") {
                timePoints[i] = "24:00";
            }
            v.push_back(toInt(timePoints[i]));
        }
        sort(v.begin(), v.end());
        string tmp = "24:00";
        int max = toInt(tmp);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int nextVal = i != n - 1 ? v[i + 1] : v[0] + max;
            int preVal = i != 0 ? v[i - 1] : v[n - 1] - max;
            ans = min(ans, v[i] - preVal);
            ans = min(ans, nextVal - v[i]);
        }
        return ans;
    }
};