class Solution:
    def permutation(self, s: str) -> List[str]:
        c = list(s)
        n = len(c)
        res = []
        def dfs(x):
            #当固定带最后一位，停止
            if x == n-1:
                res.append("".join(c))
                return res
            seen = set()
            for i in range(x,n):
                if c[i] in seen: continue  #剪枝
                seen.add(c[i]) #set集合增加元素的方法
                c[i],c[x] = c[x],c[i]
                dfs(x+1)
                c[i],c[x] = c[x],c[i]
        dfs(0)
        return res
