//good solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;

    for (int i = 0;; ++i) {
        auto it = imap.find(target - nums[i]);

        if (it != imap.end())
            return vector<int> {it->second, i};

        imap[nums[i]] = i;
    }
    }
};



// for non-duplicate vector
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        vector<int>nums2(nums);
        sort(nums2.begin(), nums2.end());

        vector<int>hold = {low, high};
        while (low < high){
            if (nums2[low] + nums2[high] == target){
            hold[0] = (find(nums.begin(), nums.end(), nums2[low])-nums.begin());
            hold[1] = (find(nums.begin(), nums.end(), nums2[high])-nums.begin());
            return hold;
            }
            else if (nums2[low] + nums2[high] > target){
                high--;
            }
            else {
                low++;
            }
            hold[0] = low;
            hold[1] = high;
        }
        return hold;
    }
};
