class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dct = {}
        for i,n in enumerate(nums):
            ob=target-n
            if ob in dct:
                #print(obj)
                return [dct[ob],i]
            else:
                dct[n] = i
        
