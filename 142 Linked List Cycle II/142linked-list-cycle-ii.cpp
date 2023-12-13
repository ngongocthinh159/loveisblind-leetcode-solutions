/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = head;

        bool found = false;
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = (f->next)->next;

            if (s == f) {
                found = true; break;
            }
        }
        if (!found) return NULL;

        ListNode* s1 = head;
        while (s != s1) {
            s = s->next;
            s1 = s1->next;
        }
        return s1;
    }
};