class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int pos = 0;
        res = dfs(s, pos, 1);
        return res;
    }
    
    string dfs(string s, int& i, int num) {
        string ss, res;
        while (i < s.size() && s[i] != ']') {
            if (s[i] == '[')
                i++;
            else if (s[i] >= '0' && s[i] <= '9') {
                int j = i;
                while (s[j] >= '0' && s[j] <= '9') j++;
                int num2 = stoi(s.substr(i, j - i));
                // jump to the index of '['
                i = j;
                ss += dfs(s, i, num2);
                // now, i is the index of ']'
                // so we need to make i++ 
                // otherwise it will break the while condition,
                // so the rest of the string won't be decoded
                
                // e.g. 3[a]2[bc]
                // now i is at '[', we need to make it at '2'
                // otherwise '2[bc]' won't be decoded
                i++;
            }
            else {
                ss += s[i++];
            }
        }
        if (num == 1)
            return ss;
        for (int i = 0; i < num; i++)
            res += ss;
        return res;
    }

};
