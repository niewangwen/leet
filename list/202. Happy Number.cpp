//same as linked cycle list

class Solution {
public:
    int getNextNum(int n) {
        int res = 0;
        while (n > 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = getNextNum(slow);
            fast = getNextNum(fast);
            fast = getNextNum(fast);
            if (fast == 1)
                return true;
            if (slow == fast)
                break;
        }
        return false;
    }
};
