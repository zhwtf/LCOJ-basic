//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
class Solution {

public:
    void moveZeroes(vector<int>& nums) {
        auto begin = find(nums.begin(), nums.end(), 0);
        if (begin == nums.end()) return; // means there is no 0 in the vector
        int s = begin - nums.begin();

        for (int i = s+1; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[s] = nums[i];
                nums[i] = 0;
                s++;
            }
        }
        return;


    }
};
