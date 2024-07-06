/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev_pos = -1, prev_val = -1, cur_pos, cur_val, next_val;
        ListNode* p = head;
        int first_pos = -1, last_pos = -1;
        int minDist = INT_MAX, mxDist = INT_MIN;
        int cnt = 0;
        while (p != NULL) {
            cur_pos = cnt;
            cur_val = p->val;
            next_val = p->next != NULL ? p->next->val : -1;
            
            bool local_max = false, local_min = false;

            if (prev_val != -1 && next_val != -1) {
                if (prev_val < cur_val && cur_val > next_val) local_max = true;
                else if (prev_val > cur_val && cur_val < next_val) local_min = true;
            }

            if (local_max || local_min) {
                if (first_pos == -1) first_pos = cur_pos;
                else {
                    last_pos = cur_pos;
                    mxDist = max(mxDist, last_pos - first_pos);
                }

                if (prev_pos != -1) {
                    minDist = min(minDist, cur_pos - prev_pos);
                }

                prev_pos = cur_pos;
            }

            prev_val = cur_val;
            p = p->next;
            cnt++;
        }
        return {minDist == INT_MAX ? -1: minDist, mxDist == INT_MIN ? -1 : mxDist};
    }
};