class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dic(256, -1);
        //using two pointers technique
        //two indexes start and i
        int start = -1, maxlen = 0;
        for (int i = 0; i < s.size(); i++){
            if (dic[s[i]] > start){
                start = dic[s[i]];
            }
            dic[s[i]] = i;
            maxlen = max(maxlen, i-start);
        }
        return maxlen;
    }
};
