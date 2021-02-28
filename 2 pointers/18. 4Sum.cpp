class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(len <= 3)
            return res;
        for(int i = 0; i < len - 3; i++){
            if(i >= 1 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < len - 2; j++){
                if(j >= i + 2 && nums[j] == nums[j - 1])
                    continue;
                int m = j + 1, n = len - 1;
                while(m < n){
                    int sum = nums[i] + nums[j] + nums[m] + nums[n];
                    if(sum == target){
                        res.push_back({nums[i], nums[j], nums[m], nums[n]});
                        m++;
                        n--;
                        while(m < n && nums[m] == nums[m - 1])
                            m++;
                        while(m < n && nums[n] == nums[n + 1])
                            n--;
                    }
                    else if(sum < target)
                        m++;
                    else
                        n--;
                }
            }
        }
        return res;
    }
};
