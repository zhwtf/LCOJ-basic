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


'''
The first while loop ensures you goes in the correct cycle which has duplicates. for example: index = [0 1 2 3 4 5 6 7]; nums=[5 2 1 3 5 7 6 4]. (slow)nums[slow] = (0)5 (5)7 (7)4 (4)5; fast = (0)5 (7)4 (5)7 (4)5; ----> when they meets at (idx=4)(value=5), you know you have a cycle.

Take a look at the cycle by the indices and values:

idx: 0--->5--->7--->4-->(goes back to idx=5)

val: 5--->7--->4--->5-->(goes back to val=7)

The second while loop will stop when "fast=0" and "slow=4" (their values = 5, the duplicate number). The duplicate number 5 is the reason why the two pointers will meet at a same index (next number). In fact, the second loop will always stop right before they meet at the first item of the cycle. (This is very similar to the problem Linked List Cycle II. )
'''

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1)
	{
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}
	return -1;
    }
};
