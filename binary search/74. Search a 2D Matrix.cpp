class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        //CONCAT THE 2D MATRIX TO AN ARRAY
        while(left <= right){
            int mid = (left + right) / 2;
            int row = mid / n, col = mid % n;
            if(target == matrix[row][col])
                return true;
            else if(target > matrix[row][col])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
