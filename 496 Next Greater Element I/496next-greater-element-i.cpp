class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> firstGreaterLeft(nums2.size());
        vector<int> firstGreaterRight(nums2.size());
        vector<int> getIndex(1e4+1);
        for (int i = 0; i < nums2.size(); i++) {
            getIndex[nums2[i]] = i;
            
            while (s.size() > 0 && nums2[i] > nums2[s.top()]) {
                firstGreaterRight[s.top()] = i;
                s.pop();
            }

            if (s.size() > 0) firstGreaterLeft[i] = s.top();
            else firstGreaterLeft[i] = -1;

            s.push(i);
        }

        while (s.size() > 0) {
            firstGreaterRight[s.top()] = -1;
            s.pop();
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int tmp = firstGreaterRight[getIndex[nums1[i]]];
            ans.push_back((tmp == -1 ? -1 : nums2[tmp]));
        }
        return ans;
    }
};