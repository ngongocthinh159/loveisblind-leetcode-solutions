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
    ListNode* mergeNodes(ListNode* head) {
        int prev_pos = -1, cur_pos = 0, sum = 0, cur_val;
        ListNode* p = head;
        ListNode dummy;
        ListNode* cur = &dummy;
        while (p != NULL) {
            cur_val = p->val;

            if (cur_val == 0) {
                if (prev_pos != -1) {
                    cur->next = new ListNode(sum);
                    cur = cur->next;

                    sum = 0;
                }

                prev_pos = cur_pos;
            } else {
                sum += cur_val;
            }

            cur_pos++;
            p = p->next;
        }
        return dummy.next;
    }
};