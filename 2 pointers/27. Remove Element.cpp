//NOTICE THE DIFFERENCE BETWEEN THIS AND 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(), i = 0, j = 0;
        while (j < len) {
            if (nums[j] == val) {
                j++;
            }
            else {
                nums[i++] = nums[j++];
            }
        }
        return i;
    }
};
