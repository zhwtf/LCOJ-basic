//Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

//You may assume the integer do not contain any leading zero, except the number 0 itself.

//The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int carry = 1;
        for (int i = size-1; i >= 0; i--){
            if (digits[i] + carry == 10){
                digits[i] = 0;

            }
            else{
                digits[i] = digits[i] + 1;
                carry = 0;
                break;
            }
        }
        if (carry == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

vector<int> plusOne(vector<int>& digits) {
    for (int i=digits.size(); i--; digits[i] = 0)
        if (digits[i]++ < 9)
            return digits;
    digits[0]++;
    digits.push_back(0);
    return digits;
}
