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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1, num2;
        ListNode* p = l1;
        while (p != NULL) {
            num1.push_back(p->val);
            p = p->next;
        }
        p = l2;
        while(p != NULL) {
            num2.push_back(p->val);
            p = p->next;
        }
        int carry = 0;
        vector<int> v;
        int i = 0, j = 0;
        while (i < num1.size() || j < num2.size()) {
            int cur;
            if (i < num1.size() && j < num2.size()) {
                cur = num1[i] + num2[j] + carry;
                i++; j++;
            } else if (i < num1.size()) {
                cur = num1[i] + carry;
                i++;
            } else if (j < num2.size()) {
                cur = num2[j] + carry;
                j++;
            }

            carry = cur/10;
            cur = cur%10; 
            v.push_back(cur);
        }
        if (carry) v.push_back(1);
        ListNode* dummy = new ListNode();
        p = dummy;
        for (auto num : v) {
            ListNode* newNode = new ListNode(num);
            p->next = newNode;
            p = p->next;
        }
        return dummy->next;
    }
};