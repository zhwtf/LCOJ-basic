'''
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
'''

class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        if (num == 10) return 1;
        int sum = 0;
        while (num != 0){
            sum = num % 10 + sum;
            num = num / 10;

        }
        return addDigits(sum);
    }
};

//O(1) solution
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
