class Solution { //3 ms Solution
public:
    bool isValid(string s) {
        stack<char> hold;
        for (size_t i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                hold.emplace(s[i]);
            }
            else {
                if (hold.empty()){ //no match for the right character
                    return false;
                }
                if ((s[i] == ')' && hold.top() != '(') || (s[i] == ']' && hold.top() != '[') || (s[i] == '}' && hold.top() != '{')){
                    return false;
                }
                hold.pop();
            }
        }
    return hold.empty();
    }
};

// 0 ms Solution
class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};
