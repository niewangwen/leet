class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, len = height.size();
        int left = 0, right = len - 1;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            res = max(res, area);
            height[left] > height[right] ? right-- : left++;
        }
        return res;
    }
};
