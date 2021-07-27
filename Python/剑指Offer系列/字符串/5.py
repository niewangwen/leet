class Solution:
    def replaceSpace(self, s: str) -> str:
        '''
        #法一
        m=[]
        for i in s:
            if i ==' ': m.append('%20')
            else:
                m.append(i)
        return "".join(m)
        '''
        #法二

        return ''.join(('%20' if c==' ' else c for c in s))
