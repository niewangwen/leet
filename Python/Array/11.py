class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i=0
        j=len(height)-1
        ans = 0
        while i < j:
            #ans = (j-i)*min(height[i],height[j])
            if height[i]<height[j]:
                ams = (j-i)*height[i]
                i+=1
            else:
                ams = (j-i)*height[j]
                j-=1
            ans = max(ans,ams)
        return ans
