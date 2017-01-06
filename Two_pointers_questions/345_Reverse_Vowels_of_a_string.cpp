//Write a function that takes a string as input and reverse only the vowels of a string.
//Given s = "hello", return "holle".

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};

class Solution {
public:
    string reverseVowels(string s) {
        if (s == "" || s.size() == 1) return s;
        int front = 0;
        int back = s.size()-1;
        vector<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (front < back){
            while (find(v.begin(), v.end(), s[front]) == v.end()){
                front++;
            }
            while (find(v.begin(), v.end(), s[back]) == v.end()){
                back--;
            }
            if(front < back){
                swap(s[front], s[back]);
                front++;
                back--;
            }
        }
        return s;
    }
};
