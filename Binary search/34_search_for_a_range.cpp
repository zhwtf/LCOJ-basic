class Solution {//using build-in function equal_range
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        pair<vector<int>::iterator, vector<int>::iterator> bounds = equal_range(nums.begin(), nums.end(), target);
        if (*(bounds.first) == target && *(--bounds.second) == target) {
            res[0] = bounds.first - nums.begin();
            res[1] = bounds.second - nums.begin();
        }

        return res;

    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        //if(nums == NULL) return vector<int>(2, -1);
        if(find(nums.begin(), nums.end(), target) != nums.end()){
            int pos = find(nums.begin(), nums.end(), target) - nums.begin();
            int ind = pos+1;
            while(ind < nums.size() && nums[ind] == target){
                ind++;
            }
            ind--;
            result[0] = pos;
            result[1] = ind;
            return result;
        }
        return result;
    }
};









//runtime error????
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int num = nums.size();
        int low = 0, high = num - 1, mid;

        vector<int> ret(-1, -1);
        //search for start position(index)
        while (low < high){
            mid = (low+high) / 2;
            if (nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid;

            }
        }
        if (nums[low] != target){
            return ret;
        }
        ret[0] = low;

        //search for end position(index)
        high = num - 1;
        while (low < high){
            mid = (low+high+1) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            }
            else{
                low = mid;
            }
        }
       ret[1] = high;
       return ret;

    }
};
