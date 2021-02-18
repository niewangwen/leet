class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        for (int i = 2; i < n + 1; i++) {
            for (int j = i / 2; j >= 1; j--) {
                if (i % j == 0) {
                    //dp[j]: minSteps to generate j
                    //1: Copy All
                    //i / j - 1: Paste Time
                    dp[i] = dp[j] + 1 + (i / j - 1);
                    //it may contain multiple results, 
                    //but the largest j must indicates the smallest dp[i], 
                    //because it means "Paste" least to get i
                    //i.e. dp[6] = dp[3] + 1 + (6 / 3 - 1) = 5;
                    //     dp[6] = dp[2] + 1 + (6 / 2 - 1) = 5;
                    //     dp[6] = dp[1] + 1 + (6 / 1 - 1) = 6;
                    break;
                }
            }
        }
        return dp[n];
    }
};
