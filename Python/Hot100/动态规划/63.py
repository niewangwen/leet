class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        temp = [[0]*n for _ in range(m)] #初始化全为0
        for i in range(n):
            if obstacleGrid[0][i]==0:
                temp[0][i]=1
            else:
                break
        for i in range(m):
            if obstacleGrid[i][0]==0:
                temp[i][0]=1
            else:
                break
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 0:
                    temp[i][j] = temp[i - 1][j] + temp[i][j - 1]
        return temp[-1][-1]
        
