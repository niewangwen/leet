/*
这道题是n维背包的变种，转化一下即可
需要注意的是若dp数组是一维的，则需要从后向前遍历，不然会出现一个num被使用两次的情况
eg: num = 3 ,so dp[3] = dp[3] || dp[3 - 3] = false || true = true
                dp[6] = ap[6] || dp[6 - 3] = false || true = true
                但是此时只有一个3，所以dp[6] = false
若从后向前，则会避免这种情况的出现
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size(), sum = 0;
        for (auto num : nums)
            sum += num;
        if (sum % 2 != 0) return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        int cnt = 0;
        for (auto num : nums) {
            cnt += num;
            for (int i = min(cnt, sum); i >=num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[sum];
    }
};
