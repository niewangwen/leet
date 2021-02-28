class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int delta = INT_MAX, len = nums.size(), res = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            int j = i + 1, k = len - 1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (abs(total - target) < delta) {
                    delta = abs(total - target);
                    res = total;
                }
                if (total < target) {
                    j++;
                }
                else {
                    k--;
                }
                
            }
        }
        return res;
    }
};
