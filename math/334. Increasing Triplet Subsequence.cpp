class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x = INT_MAX, y = INT_MAX;
        // use 3 nums to record
        for (auto num : nums) {
            if (num <= x)
                x = num; // makes x ALWAYS the SMALLEST
            else if (num <= y)
                y = num; // makes y to be the SECOND SMALLEST
            else
                return true; // in this case, we found x < y < num
        }
        return false;
    }
};
