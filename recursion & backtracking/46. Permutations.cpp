class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> one_sol, visited(nums.size(), 0);
        helper(res, nums, one_sol, visited, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int> nums, vector<int>& one_sol, vector<int>& visited, int pos) {
        if (pos == nums.size()) {
            res.push_back(one_sol);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            visited[i] = 1;
            one_sol.push_back(nums[i]);
            helper(res, nums, one_sol, visited, pos + 1);
            visited[i] = 0;
            one_sol.pop_back();
        }
    }
};
