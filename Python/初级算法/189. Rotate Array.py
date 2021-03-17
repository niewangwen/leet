'''
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

进阶：

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 

示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
数组翻转
该方法基于如下的事实：当我们将数组的元素向右移动 kk 次后，尾部 k\bmod nkmodn 个元素会移动至数组头部，其余元素向后移动 k\bmod nkmodn 个位置。

该方法为数组的翻转：我们可以先将所有元素翻转，这样尾部的 k\bmod nkmodn 个元素就被移至数组头部，然后我们再翻转 [0, k\bmod n-1][0,kmodn−1] 区间的元素和 [k\bmod n, n-1][kmodn,n−1] 区间的元素即能得到最后的答案。

我们以 n=7n=7，k=3k=3 为例进行如下展示：

操作	结果
原始数组	1~2~3~4~5~6~7                               1 2 3 4 5 6 7
翻转所有元素	7~6~5~4~3~2~1                            7 6 5 4 3 2 1
翻转 [0, k\bmod n - 1][0,kmodn−1] 区间的元素	           6 7 4 3 2 1
翻转 [k\bmod n, n - 1][kmodn,n−1] 区间的元素	           5 6 7 1 2 3 4
'''
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        l=len(nums)
        def reverse(nums,l,r):
            while l<r:
                t=nums[l]
                nums[l]=nums[r]
                l+=1
                nums[r]=t
                r-=1
        reverse(nums,0,l-1)
        reverse(nums,0,k%l-1)
        reverse(nums,k%l,l-1)
