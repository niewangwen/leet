# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        cur = pre = ListNode(0)
        while head:
            if head.val == val:
                head = head.next
                pre.next = head
            else:
                pre.next = head
                head =head.next
                pre = pre.next
        return cur.next
            
#双指针法
if head.val ==val: return head.next
        pre, cur = head, head.next
        while cur and cur.val != val:
            pre, cur = cur, cur.next
        if cur: pre.next = cur.next
        return head
