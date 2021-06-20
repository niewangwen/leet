class Solution {
public:
    vector<pair<int, int>> di {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                helper(matrix, i, j, m, n, res, memo);
            }
        }
        return res;
    }
    
    void helper(vector<vector<int>>& matrix, int i, int j, int m, int n, int& res, vector<vector<int>>& memo) {
        for (auto d : di) {
            int x = i + d.first, y = j + d.second;
            if (!check(x, y, m, n))
                continue;
            if (matrix[x][y] <= matrix[i][j])
                continue;
            if (!memo[x][y])
                helper(matrix, x, y, m, n, res, memo);
            memo[i][j] = max(memo[i][j], memo[x][y] + 1);  
        }
        if (memo[i][j] == 0)
            memo[i][j] = 1;
        res = max(res, memo[i][j]);
        return;
    }
    
    bool check(int x, int y, int m, int n) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        return false;
    }
};
