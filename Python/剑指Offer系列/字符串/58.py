class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        c = list(s)
        #使用切片函数
        for i in range(n):
            c.append(s[i])
        return "".join(c[n:])
        #不使用切片函数
        res = []
        for i in range(n,len(s)):
            res.append(c[i])
        for i in range(n):
            res.append(c[i])
        return "".join(res)
