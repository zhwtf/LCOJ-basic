'''
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

'''

//this solution can be easily generalized to "at most K duplicates"
int removeDuplicates(vector<int>& nums, int k) {
    int i = 0;
    for (int n : nums)
        if (i < k || n > nums[i-k])
            nums[i++] = n;
    return i;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};

int removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 2)
		return nums.size();
	for (int i = 2; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
			vector<int>::iterator it = nums.begin() + i;
			nums.erase(it);
			i--;
		}
	}
	return nums.size();
}




int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++)
        if (nums[i] == nums[i - 2 - count]) count++;
        else nums[i - count] = nums[i];
    return n - count;
}
