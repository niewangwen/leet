# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None #反转头
        cur = head
        while cur:
            tmp = cur.next#存储当前链表
            cur.next = pre #切断链接
            pre = cur #转换方向
            cur =tmp
        return pre
