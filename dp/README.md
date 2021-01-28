关于dp的一些思考
--------------

1. dp数组的初始化：

  对于求解 最长Longest、最多Maximum，或者是求解有多少种解决方法的问题时，由于核心公式为: `dp[i] = max(f(dp[]), g(dp[])) 或者 dp[i] = f(dp[]) + g(dp[])`
  
  故在初始化之初，可以将dp数组全部初始化为0（有时候可以为1，比如有些solution的题目，需要视情况而定）
  
  典型例题: `Maximum: 42. Trapping Rain Water`
           `Solution: 62. Unique Paths`
  
  对于求解 最少Minimum的问题时，由于核心公式为: `dp[i] = min(f(dp[]), g(dp[]))`
  
  故在初始化之初，需要将dp数组初始化为INT_MAX(如果题目中不会出现负数，也可以初始化为-1之类的负数)，否则在求解时容易出错
  
  典型例题: `322. Coin Change`
