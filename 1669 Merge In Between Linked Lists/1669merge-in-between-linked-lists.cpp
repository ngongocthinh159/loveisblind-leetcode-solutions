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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummy;
        dummy.next = list1;
        ListNode* p = &dummy;
        ListNode* prevA;
        ListNode* nextB;
        int cnt = 0;
        while (cnt <= a) {
            cnt++;
            prevA = p;
            p = p->next;
        }
        while (cnt <= b) {
            cnt++;
            p = p->next;
        }
        nextB = p->next;
        p = list2;
        prevA->next = p;
        ListNode* prev;
        while (p!=NULL) {
            prev = p;
            p = p->next;
        }
        prev->next = nextB;
        return dummy.next;
    }
};