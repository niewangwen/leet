class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if not s: return 0
        res,sign,i = 0,1,1
        binary = 2**31//10
        mz = 2**31-1
        mf = -2**31
        if s[0]=='-': sign = -1
        #记得处理i
        elif s[0] != '+': i = 0
        for c in s[i:]:
            if not '0'<=c<='9': break
            #切记这里是字符串相比较，所以用‘’引起来
            if res>binary or (res==binary and c>'7'):
                if sign==1:
                    return mz
                elif sign==-1:
                    return mf
            res = res*10 + ord(c)-ord('0')
        return sign*res
