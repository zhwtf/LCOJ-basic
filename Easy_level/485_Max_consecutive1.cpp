//Given a binary array, find the maximum number of consecutive 1s in this array.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //int size = nums.size();
        int maxi = 0;
        int count = 0;
        for (int i:nums){
            if (i == 1){
                count++;
                maxi = max(maxi, count);
            }
            else{
                count = 0;
            }


        }
        return maxi;
    }
};
