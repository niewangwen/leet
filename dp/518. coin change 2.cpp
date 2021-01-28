class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);
        for (auto coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (i == coin)
                    dp[i]++;
                else
                    dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
};
