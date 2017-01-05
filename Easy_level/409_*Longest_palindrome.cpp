//Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

//This is case sensitive, for example "Aa" is not considered a palindrome here.

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cmap;
        int num = s.size();
        int single, result, count;
        for (int i = 0; i < num; i++){
            auto it = cmap.find(s[i]);
            if (it == cmap.end()){
                cmap[s[i]] = 1;
            }
            else{
                cmap[s[i]] += 1;
            }
        }
        auto it = cmap.begin();
        while (it != cmap.end()){
            if (it->second % 2 == 0){

                result += it->second;
            }
            else {
                result += it->second;
                single++;
            }
            it++;
        }
        if (single == 0 || single == 1) return result;
        return result - single + 1;

    }
};

//other Solution
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> m(256, 0);
        for (auto& c : s) m[c-'\0']++;
        int result = 0;
        for (auto& i : m) result += i%2 ? (result%2 ? i-1 : i) : i;
        return result;
    }
};

// I count how many letters appear an odd number of times.
//Because we can use all letters, except for each odd-count letter we must leave one, except one of them we can use.
int longestPalindrome(string s) {
    int odds = 0;
    for (char c='A'; c<='z'; c++)
        odds += count(s.begin(), s.end(), c) & 1;
    return s.size() - odds + (odds > 0);
}
