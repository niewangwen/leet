class Solution:
    def fib(self, n: int) -> int:
        if n==0: return 0
        dp = [0]*(n+1) #记得dp数组长度为n+1，如此可以存放多一个位置
        dp[0] = 0
        dp[1] = 1
        for i in range(2,n+1):
            dp[i] = dp[i-1]+dp[i-2]
            dp[i] = dp[i]%(1000000007)
        return dp[n]
