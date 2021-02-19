class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //first of all, sort 2 vecs
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0, i = 0, j = 0;
        //strategy: for each child with g[i], assign the cookie(s[j]) which is JUST larger than g[i] to him/her
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                res++;
                i++;
            }
            j++;
        }
        return res;
    }
};
