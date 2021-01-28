class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (auto const& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};
