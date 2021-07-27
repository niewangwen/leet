# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        low =  head
        fast =  head
        while fast and fast.next:
            fast = fast.next.next
            low = low.next
            if low == fast:
                return True
        return False
