# Description
给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。

实现 NumArray 类：

NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j) 返回数组 nums 从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点（也就是 sum(nums[i], nums[i + 1], ... , nums[j])）

#URL
https://leetcode-cn.com/problems/range-sum-query-immutable/


# Code
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        N=len(nums)
        self.sums=[0]*(N+1)
        for i in range(N):
            self.sums[i+1]=self.sums[i]+nums[i]
        print(N)    

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j+1]-self.sums[i]
