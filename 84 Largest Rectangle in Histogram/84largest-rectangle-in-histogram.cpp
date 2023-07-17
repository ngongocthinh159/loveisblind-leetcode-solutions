class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int> firstSmallerLeft(heights.size());
        vector<int> firstSmallerRight(heights.size());
        int ans = INT_MIN;

        for (int i = 0; i < heights.size(); i++) {
            while (s.size() > 0 && heights[i] < heights[s.top()]) {
                firstSmallerRight[s.top()] = i;
                s.pop();
            }

            if (s.size() > 0) {
                if (heights[i] == heights[s.top()]) {
                    firstSmallerLeft[i] = firstSmallerLeft[s.top()];
                } else {
                    firstSmallerLeft[i] = s.top();
                }
            } else {
                firstSmallerLeft[i] = -1;
            }

            s.push(i);
        }
        while (s.size() > 0) {
            firstSmallerRight[s.top()] = heights.size();
            s.pop();
        }
        for (int i = 0; i < heights.size(); i++) {
            ans = max(ans, heights[i]*(firstSmallerRight[i] - firstSmallerLeft[i] - 1));
        }
        return ans;
    }
};