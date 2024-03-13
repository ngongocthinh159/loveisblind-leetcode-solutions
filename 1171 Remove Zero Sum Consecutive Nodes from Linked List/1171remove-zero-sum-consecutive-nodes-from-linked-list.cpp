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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        unordered_map<int,ListNode*> mp;
        mp[0] = &dummy;
        ListNode* p = head;
        int sum = 0;
        while (p != NULL) {
            while (p != NULL) {
                sum += p->val;
                if (mp.count(sum)) {
                    auto tmp = mp[sum];

                    int sum1 = sum;
                    ListNode* p1 = tmp->next;
                    while (p1 != p) {
                        sum1 += p1->val;
                        mp.erase(sum1);
                        p1=p1->next;
                    }
                    tmp->next = p->next;
                    p = p->next;
                } else {
                    mp[sum] = p;
                    p = p->next;
                }
            }
        }
        return dummy.next;
    }
};