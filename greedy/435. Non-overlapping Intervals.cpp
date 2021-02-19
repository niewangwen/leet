class Solution {
public:
        bool cmp1(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len == 0)
            return 0;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        int num = 0;
        //ALWAYS REMAIN THE SHORTEST LENGTH(AKA THE SMALLEST END)
        for(int i = 1; i < len; i++){
            if(intervals[i][0] < end){
                num++;
                if(intervals[i][1] < end)
                    end = intervals[i][1];
            }
            else{
                end = intervals[i][1];
            }
        }
        return num;
    }
    

};
