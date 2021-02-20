class Solution {
public:
    vector<int> partitionLabels(string S) {
        //record every letter's last position
        vector<int> charIdx(26, 0);
        for(int i = 0; i < S.size(); i++){
            charIdx[S[i]-'a'] = i;
        }
        
        vector<int> results;
        
        int maxIdx = -1, lastIdx = 0;
        //GREEDY: during the loop, for each letter, maxIdx = max(every visited letter's last position)
        //        so, if i == maxIdx, it means that we reach the previous letters' end position 
        for(int i = 0; i < S.size(); i++){
            maxIdx = max(maxIdx, charIdx[S[i]-'a']);
            if(i == maxIdx) {
                results.push_back(maxIdx - lastIdx + 1);
                lastIdx = i+1;
            }
        }
        return results;
    }
};
