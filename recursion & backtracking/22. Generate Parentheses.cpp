class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, 0, 0);
        return res;
    }
    
    void helper(vector<string>& res, string s, int n, int left, int right) {
        if (right > left || left > n || right > n)
            return;
        if (right + left == 2 * n) {
            res.push_back(s);
            return;
        }
        helper(res, s + "(", n, left + 1, right);
        helper(res, s + ")", n, left, right + 1);
    }
};
