class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, len = prices.size(), cur = prices[0];
        for (int i = 1; i < len; i++) {
            if (prices[i] > cur) {
                res += prices[i] - cur;
                cur = prices[i];
            }
            else
                cur = prices[i];
        }
        return res;
    }
};
