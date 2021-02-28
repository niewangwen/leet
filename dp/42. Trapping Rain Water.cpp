class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), res = 0;
        vector<int> lh(len, 0), rh(len, 0);
        for (int i = 1; i < len; i++)
            lh[i] = max(lh[i - 1], height[i - 1]);
        for (int i = len - 2; i >= 0; i--)
            rh[i] = max(rh[i + 1], height[i + 1]);
        for (int i = 0; i < len; i++)
            res += height[i] < min(lh[i], rh[i]) ? min(lh[i], rh[i]) - height[i] : 0;
        return res;
    }
};
