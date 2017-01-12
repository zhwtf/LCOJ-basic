'''
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
'''

//using unordered_map
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (char i:magazine){
            ++map[i];
        }
        for (char j:ransomNote){
            if (--map[j] < 0) return false;
        }
        return true;
    }
};

//use a vector with size 26
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vec(26, 0);
        for (int i = 0; i < magazine.size(); ++i)
            ++vec[magazine[i] - 'a'];
        for (int j = 0; j < ransomNote.size(); ++j)
            if (--vec[ransomNote[j] - 'a'] < 0)
                return false;
        return true;
    }
};
