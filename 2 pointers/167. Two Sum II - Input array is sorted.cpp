class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int i = 0, j = len - 1;
        while (i <= j) {
            if (numbers[i] + numbers[j] == target)
                break;
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return vector<int> {i + 1, j + 1};
    }
};
