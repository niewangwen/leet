class Solution:
    def firstUniqChar(self, s: str) -> str:
        '''
        a = dict()
        n = len(s)
        for i in range(n):
            if s[i] in a:
                a[s[i]] += 1
            else:
                a[s[i]] = 1
        for i,val in enumerate(a):
            if a[val] == 1:
                return val
        return " "
        '''
        dic = dict()
        #c in dic是一个bool值，用于返回true、false的判断~
        for c in s:
            dic[c] = not c in dic
        for c in s:
            if dic[c]: return c
        return ' '
