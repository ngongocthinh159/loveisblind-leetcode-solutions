class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        queue<int> q;
        q.push(start);
        int level = 1;

        while (q.size() > 0) {
            int levelLength = q.size();

            for (int i = 0; i < levelLength; i++) {
                int curIndex = q.front();
                q.pop();
                visited[curIndex] = true;
                if (arr[curIndex] == 0) return true;
                int leftIndex = curIndex - arr[curIndex]%arr.size();
                int rightIndex = curIndex + arr[curIndex]%arr.size();
                if (0 <= leftIndex && leftIndex < arr.size() && !visited[leftIndex]) {
                    q.push(leftIndex);
                }
                if (0 <= rightIndex && rightIndex < arr.size() && !visited[rightIndex]) {
                    q.push(rightIndex);
                }
            }

            level++;
        }

        return false;
    }
};