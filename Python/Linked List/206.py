pre = None #这是python定义空链表的规则
        cur = head #双指针法
        while cur:
            tmp = cur.next #定义此变量储存中间值
            cur.next = pre #转向
            pre = cur #后移
            cur = tmp #后移
            #head.next = ListNode(head.val)
            #head = head.next
        return pre
