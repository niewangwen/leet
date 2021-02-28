class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (haystack[i] != needle[j]) {
                //everytime h[i] mismatches n[j], we need to begin at next index
                //i.e. mississipi
                //      issip
                //we need to start next round at m[2]->ssissipi, not m[i++] = m[6]->sipi
                i = i - j + 1;
                j = 0;
            }
            else {
                i++;
                j++;
            }
        }
        return j == len2 ? i - len2 : -1;
    }
};
