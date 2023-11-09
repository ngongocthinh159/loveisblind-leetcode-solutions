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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* p = head;
        ListNode* prev = &dummy;
        while (p != NULL) {
            ListNode* start = p;
            p = p->next;
            bool notUnique = false;
            while (p != NULL && p->val == start->val) {
                p = p->next;
                notUnique = true;
            }
            if (notUnique) prev->next = p;
            else prev = start;
        }
        return dummy.next;
    }
};