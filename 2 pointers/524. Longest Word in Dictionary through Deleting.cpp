class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res;
        int len_s = s.size(), len_r = 0;
        sort(dictionary.begin(), dictionary.end());
        for (auto word : dictionary) {
            int len_w = word.size();
            if (len_w <= len_r)
                continue;
            int i = 0, j = 0;
            while (i < len_s && j < len_w) {
                if (s[i++] == word[j])
                    j++;
            }
            if (j == len_w && len_w > len_r) {
                len_r = len_w;
                res = word;
            }
        }
        return res;
    }
};
