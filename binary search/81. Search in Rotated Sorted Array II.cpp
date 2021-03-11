class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            while (left < len && nums[left] == nums[mid])
                left++;
            while (right >= 0 && nums[right] == nums[mid])
                right--;
            if (left > mid || right < mid)
                continue;
            if (nums[mid] > nums[left]) {
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return false;
    }
};
