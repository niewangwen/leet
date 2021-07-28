class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        low = 0 
        high = int(c**(0.5)) 
        while low<=high:
            dd = low*low + high*high
            if dd==c:
                return True
            elif dd < c:
                low +=1
            else:
                high -=1
        return False
