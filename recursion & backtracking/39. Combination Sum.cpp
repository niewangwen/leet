//i.e. candi = [2,3,6,7] target = 7
//     res = [[2,2,3],[7]]

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> one_sol;
        helper(candidates, res, target, 0, one_sol, 0);
        return res;
    }
    
    void helper(vector<int> candi, vector<vector<int>>& res, int target, int sum, vector<int>& one_sol, int cur_pos) {
        if (target < sum)
            return;
        if (target == sum) {
            res.push_back(one_sol);
            return;
        }
        //we need to add CUR_POS in the function and use it here
        //otherwise the answer will be like [[2,2,3],[2,3,2],[3,2,2]]
        //how to avoid duplicate result?
        //we may notice that in [2,3,2] and [2,2,3], there is always some element whose index is SMALLER but appear in the array LATER
        //so it tells us: EVERY TIME RECORD THE INDEX, and in the next round of recursion, START FROM THE RECORDED INDEX, DO NOT START FROM THE BEGINNING
        //and it will solve the problem
        for (int i = cur_pos; i < candi.size(); i++) {
            one_sol.push_back(candi[i]);
            helper(candi, res, target, sum + candi[i], one_sol, i);
            one_sol.pop_back();
        }
    }
};
