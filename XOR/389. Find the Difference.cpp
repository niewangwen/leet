class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        int i = 0;
        while (i < s.size()) {
            res ^= s[i] ^ t[i];
            i++;
        }
        return res ^ t[i];
    }
};
