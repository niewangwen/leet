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
        ListNode* t1 = reverse(l1), *t2 = reverse(l2), *dummy = new ListNode(0);
        ListNode* s = dummy;
        int jinwei = 0;
        while (t1 && t2) {
            int sum = t1->val + t2->val + jinwei;
            jinwei = sum / 10;
            ListNode* news = new ListNode(sum % 10);
            s->next = news;
            s = s->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        while (t1) {
            int sum = t1->val + jinwei;
            jinwei = sum / 10;
            ListNode* news = new ListNode(sum % 10);
            s->next = news;
            s = s->next;
            t1 = t1->next;
        }
        while (t2) {
            int sum = t2->val + jinwei;
            jinwei = sum / 10;
            ListNode* news = new ListNode(sum % 10);
            s->next = news;
            s = s->next;
            t2 = t2->next;
        }
        if (jinwei) {
            ListNode* news = new ListNode(jinwei);
            s->next = news;
            s = s->next;
        }
        return reverse(dummy->next);
        //return s;
        
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* p = NULL;
        while (head) {
            ListNode* t = head->next;
            head->next = p;
            p = head;
            head = t;
        }
        return p;
    }
};
