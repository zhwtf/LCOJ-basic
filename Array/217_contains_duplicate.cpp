//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        //if (size == 0 || size == 1) return false;
        //if (size == 2) return nums[0] == nums[1];
        unordered_map<int, int>m;
        for (int i:nums){
            if (++m[i] > 1) return true;
        }
        return false;
    }
};

//using set since set only contains distinct numbers
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
