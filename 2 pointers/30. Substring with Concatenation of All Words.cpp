class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> m;
        for (auto word : words)
            m[word]++;
        int len = s.size(), nums = words.size(), len_w = words[0].size();
        int i = 0, j = 0;
        //NOTICE: i "<=" len - nums * len_w, NOT ONLY "<"
        //because if len == nums * len_w, we STILL need to check at i == 0
        for (int start = 0; start < len_w; start++) {
            int i = start;
            while (i <= len - nums * len_w) {
                unordered_map<string, int> record;
                int j = i;
                while (j < len) {
                    string subs = s.substr(j, len_w);
                    //this branch is use to reduce runtime
                    if (!m.count(subs)) {
                        i = j;
                        break;
                    }
                    //this loop is to make (i, j) a SLIDING WINDOW
                    while (record[subs] >= m[subs]) {
                        if (record.count(s.substr(i, len_w)))
                            record[s.substr(i, len_w)]--;
                        i += len_w;
                    }
                    j += len_w;
                    record[subs]++;
                    if (j - i == nums * len_w) {
                        res.push_back(i);
                        break;
                    }
                }
                i += len_w;
            }
        }
        
        return res;
    }
};
