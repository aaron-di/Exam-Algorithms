/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
class Solution {
public:
    ListNode* filterList(ListNode* head) {
        bool st[10010] = {};
        st[abs(head->val)] = true;
        auto p = head;
        while (p->next) {
            int x = abs(p->next->val);
            if (st[x]) {
                auto q = p->next;
                p->next = q->next;
                delete q;
            } else {
                st[x] = true;
                p = p->next;
            }
        }
        return head;
    }
};
 */