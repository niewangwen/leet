class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        '''解法一:不限制只能向下或向右移动
        m = len(grid)
        n = len(grid[0])
        dp = [[0]*(n+1) for _ in range(m+1)]
        #dp[1][1] = grid[0][0]
        for i in range(1,m+1):
            for j in range(1,n+1):
                if j==1:
                    dp[i][j] = dp[i-1][j]+grid[i-1][j-1]
                elif i==1:
                    dp[i][j] = dp[i][j-1]+grid[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1]
        print(dp)
        return dp[-1][-1]

        if not grid or not grid[0]:
            return 0
        '''
        #解法二
        rows, columns = len(grid), len(grid[0])
        dp = [[0] * columns for _ in range(rows)]
        dp[0][0] = grid[0][0]
        for i in range(1, rows):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for j in range(1, columns):
            dp[0][j] = dp[0][j - 1] + grid[0][j]
        for i in range(1, rows):
            for j in range(1, columns):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        
        return dp[rows - 1][columns - 1]
