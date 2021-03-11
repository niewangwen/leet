class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        int left = 0, right = len - 1, mid;
        //find the starting index
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                right = mid - 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        //CAUTION: if all the values < target, right won't change during the first loop
        //so right == len - 1, and right + 1 will exceed array's range
        if (right + 1 < len && nums[right + 1] == target)
            res.push_back(right + 1);
        else
            return {-1, -1};
        left = 0, right = len - 1;
        //find the right index
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        res.push_back(left - 1);
        return res;        
    }
};
