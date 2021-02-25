class Solution {
public:
    bool allVisited(unordered_map<char, int>& m) {
        for (auto iter : m) {
            if (iter.second > 0)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        //record every character in t
        for (auto c : t) {
            m[c]++;
        }
        string res;
        int i = 0, j = 0, len = s.size(), min_len = INT_MAX;
        while (i < len && j < len) {
            if (!m.count(s[j]))
                j++;
            // if s[j] is in t
            else {
                m[s[j]]--;
                //check if every letter in t is visited
                //visited means they all appear in current [i, j]
                //NOTICE: if t = "AABC", it means AT LEAST 2A, 1B, 1C should appear in [i, j]
                //if there's 3 or more A in [i, j], it's ok
                //but if there's only 1 A in [i, j], it's wrong
                if (allVisited(m)) {
                    //we want to get MINIMUM substr, so left pointer need to go right
                    //until break the allVisited condition
                    //then we get one suitable substr
                    while (allVisited(m)) {
                        if (m.count(s[i]))
                            m[s[i]]++;
                        i++;
                    }
                    int cur_len = j - (i - 1) + 1;
                    if (cur_len < min_len) {
                        min_len = cur_len;
                        res = s.substr(i - 1, min_len);
                    }
                    //NOTICE that s[j] has been counted at the beginning of the ELSE branch
                    //so at last we need to let j++
                    j++;
                }
                else {
                    j++;
                }
            }
        }
        return res;
    }
};
