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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* test = head;
        while (test) {
            len++;
            test = test->next;
        }
        if (len == 0 || len == 1 || k % len == 0)
            return head;
        k = len - k % len;
        ListNode* prev = head;
        while (k - 1) {
            prev = prev->next;
            k--;
        }
        ListNode* newH = prev->next, *h = prev->next;
        prev->next = NULL;
        while(h && h->next)
            h = h->next;
        h->next = head;
        return newH;
    }
};
