//Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

class Solution {
public:
    string addStrings(string num1, string num2) {
        int s1 = num1.size();
        int s2 = num2.size();
        int h = s1>s2 ? s1+1:s2+1;
        string sum(h, '0');
        int i = s1-1;
        int j = s2-1;
        int carry = 0;
        int sumsize = sum.size()-1;
        while (i>=0 || j>=0 || (sumsize >= 0)){
            if(i>=0){
                carry += num1[i] - '0';
                i--;
            }
            if(j>=0){
                carry += num2[j] - '0';
                j--;
            }

            sum[sumsize] = carry % 10 + '0';
            sumsize--;
            carry = carry / 10;
        }
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
};
