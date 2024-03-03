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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* p1 = head;
        ListNode* p2 = head;
        int cnt = 0;
        while (true) {
            cnt++;
            p2=p2->next;
            if (cnt==n) break;
        }
        while (p2!=NULL) {
            prev = p1;
            p1=p1->next;
            p2=p2->next;
        }
        prev->next = p1->next;
        return dummy.next;
    }
};