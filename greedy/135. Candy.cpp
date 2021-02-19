class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if (len == 1) return 1;
        vector<int> candies(len, 1);
        //first loop, makes sure children with a higher rating get more candy than its LEFT neighbor
        for(int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        } 
        
        //second loop, makes sure children with a higher rating get more candy than its RIGHT neighbor
        for(int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                //we need to choose the higher one between c[i] and c[i + 1] + 1
                //because c[i + 1] + 1 may flush the previous res, break the restriction
                //i.e.         1 2 4                           1 4
                //first loop:  1 2 3                           1 2
                //second loop: 1 2 2(it needs to maintain 3)   1 2 (WRONG)
                //it shows "greedy" in another view:
                //WE ALWAYS WANT MOST/LEAST BASED ON CURRENT SITUATION
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        int res = 0;
        for (auto c : candies)
            res += c;
        return res;
    }
};
