class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        #普通dp
        '''
        dp = [[1]*n] + [[1]+[0] * (n-1) for _ in range(m-1)]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i-1][j]+dp[i][j-1]
        return dp[-1][-1]
        '''
        #节省空间
        cur = [1] * n 
        for i in range(1,m):
            for j in range(1,n):
                cur[j] += cur[j-1]
        return cur[-1]
