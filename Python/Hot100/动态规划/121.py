class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #动态规划做法
        n = len(prices)
        dp = [0]*n
        minp = prices[0]
        if n == 0: return 0
        for i in range(n):
            minp = min(minp,prices[i])
            dp[i] = max(dp[i-1],prices[i]-minp)
        return max(dp)
        #一次遍历法~
        minp = float("INF")
        maxprofit = 0
        for price in prices:
            minp = min(minp,price)
            maxprofit = max(maxprofit,price-minp)
        return maxprofit
