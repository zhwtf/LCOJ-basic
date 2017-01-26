'''
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.
'''

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;

        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }

        return result;
    }
};


int missingNumber(vector<int>& nums) {
    long n = nums.size();
    return n * (n+1) / 2 - accumulate(begin(nums), end(nums), 0);
}

//
