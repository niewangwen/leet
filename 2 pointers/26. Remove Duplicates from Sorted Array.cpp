class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 0, j = 0;
        while (j < len) {
            if (nums[i] == nums[j]) {
                j++;
            }
            else {
                nums[++i] = nums[j++];
            }
        }
        //ATTENTION when len == 0
        return len == 0 ? 0 : i + 1;
    }
};
