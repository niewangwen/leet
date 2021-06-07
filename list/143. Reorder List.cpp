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
    void reorderList(ListNode* head) {
        // get the medium of the list
        if (!head->next || !head->next->next)
            return;
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //break the list into 2 parts
        ListNode* med = slow->next, *pre = NULL;
        slow->next = NULL;
        
        //reverse the second list
        while (med) {
            ListNode* t = med->next;
            med->next = pre;
            pre = med;
            med = t;
        }
        
        //merge 2 list
        ListNode *h = head;
        while (pre) {
            ListNode *hnext = h->next, *prenext = pre->next;
            h->next = pre;
            pre->next = hnext;
            h = h->next->next;
            pre = prenext;
        }
    }
};
