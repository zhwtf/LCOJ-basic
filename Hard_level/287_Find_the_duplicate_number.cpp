//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
//find the duplicate one.

int findDuplicate(vector<int>& nums) {
    int n=nums.size()-1;
    int low=1;
    int high=n;
    int mid;
    while(low<high){
        mid=(low+high)/2;
        int count=0;
        for(int num:nums){
            if(num<=mid) count++;
        }
        if(count>mid) high=mid;
        else low=mid+1;
    }
    return low;
}


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //using unordered map
        //int n = nums.size()-1;
        unordered_map<int, int>m;
        for(int i:nums){
            if(++m[i] > 1) return i;
        }
        return 0;
    }
};
