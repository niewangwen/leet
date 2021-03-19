class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> one_sol;
        helper(res, one_sol, n, k, 0, 1);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& one_sol, int n, int k, int total, int cur_pos) {
        if (total == k) {
            res.push_back(one_sol);
            return;
        }
        
        for (int i = cur_pos; i <= n; i++) {
            one_sol.push_back(i);
            helper(res, one_sol, n, k, total + 1, i + 1);
            one_sol.pop_back();
        }
    }
};
