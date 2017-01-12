//Given two binary strings, return their sum (also a binary string).
class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            //time complexity is 1 + 2 + ... + n = O(n^2)
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }
};


// the time complexity becomes O(n)
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        string sum;
        int carry = 0;

        int i = n - 1, j = m - 1;
        while (i >= 0 || j >= 0 || carry > 0){
            if (i >= 0) {
                carry += a[i] - '0';
                i -= 1;
            }
            if (j >= 0) {
                carry += b[j] - '0';
                j -= 1;
            }
            sum += (carry % 2) + '0';
            carry /= 2;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
