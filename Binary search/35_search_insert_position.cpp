class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low < high){
            mid = low + (high - low)/2; //in order to avoid overflow
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return nums[low]>=target ? low:low+1;
    }
};


// other approach
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }

        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
        return low;
    }
};
