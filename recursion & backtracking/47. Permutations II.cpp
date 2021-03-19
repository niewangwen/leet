class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> one_sol, visited_during_all_level(nums.size(), 0);
        helper(res, nums, one_sol, visited_during_all_level, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int> nums, vector<int>& one_sol, vector<int>& visited_during_all_level, int total) {
        if (total == nums.size()) {
            res.push_back(one_sol);
            return;
        }
        
        set<int> visited_at_cur_level;
        for (int i = 0; i < nums.size(); i++) {
            if (visited_during_all_level[i])
                continue;
            if (visited_at_cur_level.count(nums[i]))
                continue;
            visited_at_cur_level.insert(nums[i]);
            visited_during_all_level[i] = 1;
            one_sol.push_back(nums[i]);
            helper(res, nums, one_sol, visited_during_all_level, total + 1);
            visited_during_all_level[i] = 0;
            one_sol.pop_back();
        }
    }
};
