class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                if (j == 1)
                    dp[0][j] = dp[0][0];
                else
                    dp[0][j] = dp[0][j - 1] || dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // if * means 0 appearance of its preceding letter, dp[j][j] = dp[i][j - 2]
                    // if * means 1 appearance of its preceding letter, dp[j][j] = dp[i][j - 1]
                    // if * means 2 or more appearance of its preceding letter, 
                    //      first of all, we need to check if the preceding letter equals to s[j - 1]: p[j - 2] == s[i - 1] || p[j - 2] == '.'
                    //      secondly, if the first step is true, it means s[i - 1] IS PART OF 'preceding letter + *',
                    //                then, we need to check IF s[i - 2] IS PART OF 'preceding letter + *', 
                    //                AND THIS STEP IS RECURSIVELY, SO WE ONLY NEED dp[i - 1][j]
                    dp[i][j] = (j >= 2 && dp[i][j - 2]) || dp[i][j - 1] || (dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
                }
                else if (p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = dp[i - 1][j - 1] && p[j - 1] == s[i - 1];
            }
        }
        return dp[m][n];
    }
};
