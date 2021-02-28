class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            //remove duplicate at i
            if (i >= 1 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = len - 1, val = -nums[i];
            while (left < right) {
                //remove duplicate at left
                if (left != i + 1 && nums[left] == nums[left - 1]) {
                    left++;
                    continue;
                }
                //remove duplicate at right
                if (right != len - 1 && nums[right] == nums[right + 1]) {
                    right--;
                    continue;
                }
                if (nums[left] + nums[right] == val) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] > val)
                    right--;
                else
                    left++;
            }
        }
        return res;
    }
};
