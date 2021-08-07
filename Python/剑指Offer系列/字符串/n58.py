class Solution:
    def reverseWords(self, s: str) -> str:
        '''
        #分割函数
        s = s.strip() # 删除首尾空格
        strs = s.split() # 分割字符串
        strs.reverse() # 翻转单词列表
        return ' '.join(strs) # 拼接为字符串并返回
        '''

        #双指针法
        s = s.strip() # 删除首尾空格
        i = j = len(s) - 1
        res = []

        while i >=0:
            while i>=0 and s[i] !=' ':
                i = i-1
            res.append(s[i+1:j+1])
            while s[i]==' ':
                i = i-1
            j = i
        return " ".join(res)
