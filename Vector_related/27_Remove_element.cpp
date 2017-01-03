class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)return 0;
        while(find(nums.begin(), nums.end(), val) != nums.end()){
            nums.erase(find(nums.begin(), nums.end(), val));
        }
        return nums.size();
    }
};
