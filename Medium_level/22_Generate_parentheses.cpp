//recurive solution
//The idea is intuitive. Use two integers to count the remaining left parenthesis (n) and the right parenthesis (m) to be added.
//At each function call add a left parenthesis if n >0 and add a right parenthesis if m>0. Append the result and terminate recursive calls when both m and n are zero.


//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
class Solution{
public:
  vector<string> generateParenthesis(int n){
    vector<string> result;
    recur(result, "", n, 0);
    return result;

  }

  void recur(vector<string> &v, string str, int n, int m) {
    if (n==0 && m==0){
      v.push_back(str);
      return;
    }
    if (m > 0) {
      recur(v, str + ")", n, m-1);
    }
    if (n > 0) {
      recur(v, str + "(", n-1, m+1);
    }
  }
};
