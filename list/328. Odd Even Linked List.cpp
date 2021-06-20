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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* odd_prev = head, *even_head = head->next, *even_prev = head->next;
        while (even_prev && even_prev->next) {
            ListNode* odd_tail = even_prev->next, *even_tail = even_prev->next->next;
            odd_prev->next = odd_tail;
            even_prev->next = even_tail;
            odd_tail->next = even_head;
            odd_prev = odd_prev->next;
            even_prev = even_prev->next;
        }
        return head;
    }
};
