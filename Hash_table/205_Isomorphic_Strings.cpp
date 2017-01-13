'''
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
'''

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> smap(256, -1);
        vector<int> tmap(256, -1);

        for(int i = 0; i<s.length(); i++)
        {
            if (smap[s[i]] != tmap[t[i]]) return false;
            smap[s[i]] = tmap[t[i]] = i;
        }
        return true;
    }
};
