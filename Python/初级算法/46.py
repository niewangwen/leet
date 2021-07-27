class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        def dfs(x):
            if x == n-1: 
                res.append(nums[:])
                return res
            #seen = set()
            for i in range(x,n):
                #if nums[i] in seen: continue
                #seen.add(nums[i])
                nums[i],nums[x] = nums[x],nums[i]
                dfs(x+1)
                nums[i],nums[x] = nums[x],nums[i]
        dfs(0)
        return res
