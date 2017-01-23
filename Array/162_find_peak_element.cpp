'''
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
'''


//Sequential Search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i ++)
        {
            if(nums[i] < nums[i-1])
            {// <
                return i-1;
            }
        }
        return nums.size()-1;
    }
};





//Binary Search: iteration


class Solution {
public:
    int findPeakElement(const vector<int> &num)
    {
        int low = 0;
        int high = num.size()-1;

        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};
