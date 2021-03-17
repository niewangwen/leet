class Solution {
public:
    vector<string> candi = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string s;
        if (digits.size() == 0)
            return res;
        helper(res, digits, 0, s);
        return res;
    }
    
    //res use to record all results
    //digits use to find which character we are using at this step
    //pos use to find the index of the character we are using && record answer's length
    //s use to record one valid result
    void helper(vector<string>& res, string digits, int pos, string& s) {
        if (s.size() == digits.size()) {
            res.push_back(s);
            return;
        }
        
        for (int i = 0; i < candi[int(digits[pos]) - '2'].size(); i++) {
            s += candi[digits[pos] - '2'][i];
            helper(res, digits, pos + 1, s);
            s.pop_back();
        }
    }
};
