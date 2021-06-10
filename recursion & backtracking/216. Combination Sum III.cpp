class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sol;
        helper(k, n, 0, 0, 1, res, sol);
        return res;
    }
    void helper(int k, int n, int used_num, int sum, int start_num, vector<vector<int>>& res, vector<int>& sol) {
        if (used_num == k) {
            if (sum == n)
                res.push_back(sol);
            return;
        }
        for (int i = start_num; i <= 9; i++) {
            sol.push_back(i);
            helper(k, n, used_num + 1, sum + i, i + 1, res, sol);
            sol.pop_back();
        }
    }
};
