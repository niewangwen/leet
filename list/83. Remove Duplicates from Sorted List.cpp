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
        ListNode* h = head;
        while (h && h->next) {
            if (h->val == h->next->val) {
                h->next = h->next->next;
                //CAUTION: DO NOT "h = h->next" here
                //i.e. 1->2(1)->2(2)->2(3)->3
                //if h == 2(1), it will delete 2(2), BUT IT STILL NEED DELETE 2(3)
                //so, if we h = h->next here, h will jump to 2(3),
                //IN THAT CASE, 2(1) AND 2(3) will be saved
            }
            else
                h = h->next;
        }
        return head;
    }
};
