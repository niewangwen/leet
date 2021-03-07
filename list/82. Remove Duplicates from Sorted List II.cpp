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
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        ListNode* h = dummy;
        while (h && h->next && h->next->next) {
            if (h->next->val != h->next->next->val)
                h = h->next;
            else {
                ListNode* dup = h->next->next;
                while (dup && dup->next && dup->val == dup->next->val) {
                    dup = dup->next;
                }
                h->next = dup->next;
                //CAUTION: DO NOT USE h = h->next HERE
                //i.e. 1->2->2->3(1)->3(2)->4
                //we will delete all 2's in first iteration
                //BUT IF WE USE h = h->next, h will jump to 3(1)
                //AND both 3(1), 3(2) WILL BE SAVED
                //h = h->next;
            }
            
        }
        return dummy->next;
    }
};
