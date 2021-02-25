class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        unordered_set<char> c;
        int l = 0, r = 0, res = 0;
        while(r < len){
            if(!c.count(s[r])){
                res = max(res, r - l + 1);
                c.insert(s[r++]);
            }
            else{
                c.erase(s[l++]);
            }
        }
        return res;
    }
};
