class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        dfs(res, 1, n);
        return res;
    }
    
    void dfs(vector<int>& res, int num, int n) {
        int cur = num;
        while (((num % 10 == 0 && cur - num <= 9) || (num % 10 == 1 && cur - num < 9)) && cur <= n) {
            res.push_back(cur);
            if (cur * 10 <= n)
                dfs(res, cur * 10, n);
            cur++;
        }
    }
};
