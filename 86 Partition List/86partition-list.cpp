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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(-1);
        ListNode dummy2(-2);
        ListNode* p = head;
        ListNode* i = &dummy1;
        ListNode* j = &dummy2;

        while (p != NULL) {
            ListNode* next = p->next;
            if (p->val < x) {
                i->next = p;
                p->next = NULL;
                i = p;
            } else {
                j->next = p;
                p->next = NULL;
                j = p;
            }
            p = next;
        }
        i->next = dummy2.next;
        return dummy1.next;
    }
};