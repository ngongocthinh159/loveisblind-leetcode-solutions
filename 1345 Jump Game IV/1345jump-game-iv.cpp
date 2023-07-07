class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1) return 0;
        map<int, vector<int>> map;
        for (int i = 0; i < arr.size(); i++) {
            if (map.find(arr[i]) == map.end()) {
                vector<int>& indexList = map[arr[i]];
                indexList.push_back(i);
            } else {
                map[arr[i]].push_back(i);
            }
        }

        queue<int> q;
        vector<bool> alreadyPush(arr.size(), false);
        set<int> set;
        q.push(0);
        alreadyPush[0] = true;
        int level = 1;

        while (q.size() > 0) {
            int levelLength = q.size();

            for (int i = 0; i < levelLength; i++) {
                int curIndex = q.front();
                q.pop();
                if (curIndex == arr.size() - 1) return level - 1;

                // Push neightbors with same value
                if (set.find(arr[curIndex]) == set.end()) {
                    set.insert(arr[curIndex]);
                    vector<int>& curList = map[arr[curIndex]];
                    for (int j = 0; j < curList.size(); j++) {
                        if (!alreadyPush[curList[j]]) {
                            q.push(curList[j]);
                            alreadyPush[curList[j]] = true;
                            // if (curList[j] == arr.size() - 1) return level;
                        }
                    }
                }
                
                if (curIndex + 1 < arr.size() && !alreadyPush[curIndex + 1]) {
                    q.push(curIndex + 1);
                    alreadyPush[curIndex + 1] = true;
                    // if (curIndex + 1 == arr.size() - 1) return level;
                }
                if (curIndex - 1 >= 0 && !alreadyPush[curIndex - 1]) {
                    q.push(curIndex - 1);
                    alreadyPush[curIndex - 1] = true;
                    // if (curIndex - 1 == arr.size() - 1) return level;
                }
                
            }

            level++;
        }

        return -1;
    }
};