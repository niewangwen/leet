class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x = INT_MAX, y = INT_MAX;
        // use 3 nums to record
        // NOTICE: x is ONLY the smallest among TRIPLET
        //         x IS NOT the smallest among ALL numbers
        for (auto num : nums) {
            if (num <= x)
                x = num; // makes x ALWAYS the SMALLEST in these 3 nums
            else if (num <= y)
                y = num; // makes y to be the SECOND SMALLEST in these 3 nums
            else
                return true; // in this case, we found x < y < num
        }
        return false;
    }
};
