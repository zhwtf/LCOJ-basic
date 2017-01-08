//Given an array of integers and an integer k,
//find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        if (k <= 0) return false;
        unordered_map<int, int>m;
        for(int i= 0; i < size; i++){
            if (++m[nums[i]] > 1){
                for (int j = i - 1; j >= 0 && abs(j-i) <= k; j--){
                    if (nums[j] == nums[i]) return true;
                }
            }
        }
        return false;
    }
};

//using set
//The basic idea is to maintain a set s which contain unique values from nums[i - k] to nums[i - 1],
//if nums[i] is in set s then return true else update the set.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;

       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;

       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }

       return false;
    }
};
