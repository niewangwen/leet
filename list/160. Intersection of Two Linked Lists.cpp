/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// if there is no intersection, 2 pointer will equal to NULL at last
// else, they will meet at the intersection

// illustration: 
// assume x = len(independent headA), y = len(independent headB), z = len(common len) (z maybe 0)
// 1) z == 0
//    pointer a will travel (x + y) distance, pointer b will travel (y + x) distance
//    so they will equal to NULL (a at headB's tail, b at headA's tail)
// 2) z != 0
//    pointer a will travel (x + z + y) distance, pointer b will travel (y + z + x) distance
//    so they will meet at intersection because the previous travel length is equal
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
