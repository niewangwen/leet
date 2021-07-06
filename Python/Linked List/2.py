class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        extra = 0 #用来储存是否进位
        root = n = ListNode(0) #一般先用0占位
        while l1 or l2 or extra: #补充extra保证最后的进位
            v1 = v2 =0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            extra, val =divmod(v1+v2+extra,10)
            n.next=ListNode(val)
            n = n.next
        return root.next
