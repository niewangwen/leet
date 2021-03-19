//i.e. candidates = [10,1,2,7,6,1,5], target = 8
//     results = [[1,1,6],[1,2,5],[1,7],[2,6]]

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> one_sol;
        //we need to sort at first
        //otherwise in the recursion function, the "if (i > cur_pos && candi[i] == candi[i - 1])" won't help
        sort(candidates.begin(), candidates.end());
        helper(candidates, res, one_sol, target, 0, 0);
        return res;
    }
    
    void helper(vector<int> candi, vector<vector<int>>& res, vector<int>& one_sol, int target, int sum, int cur_pos) {
        if (sum > target)
            return;
        if (sum == target) {
            res.push_back(one_sol);
            return;
        }
        for (int i = cur_pos; i < candi.size(); i++) {
            //since every iteration in one recursion function means all the possibilities at this stage's recursion
            //we need to avoid using the same value at ONE RECURSION, but it's okay to use the same value across the recursion level
            //i.e. [1(1), 1(2), 2] target = 3
            // 1st  2nd  3rd  (level of recursion)
            // 1(1) 1(2)  2
            //      2
            // 1(2) 2
            // 2
            //using the below branch we can avoid picking 1(2) at 1st recursion and picking 2 at 2nd recursion
            if (i > cur_pos && candi[i] == candi[i - 1])
                continue;
            one_sol.push_back(candi[i]);
            //everytime the cur_pos = i + 1 to avoid visiting the same index
            helper(candi, res, one_sol, target, sum + candi[i], i + 1);
            one_sol.pop_back();
        }
    }
};
