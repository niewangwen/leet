class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size(), res = INT_MAX;
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            //res = min(res, nums[mid]);
            if (nums[left] < nums[mid]) {
                res = min(res, nums[left]);
                left = mid + 1;
            }
            //since all the value is distinct in the array
            //this branch is for right == left + 1, mid == left
            else if (nums[left] == nums[mid]) {
                res = min(res, nums[left]);
                left++;
            }
            else {
                res = min(res, nums[mid]);
                right = mid - 1;
            }
        }
        return res;
    }
};
