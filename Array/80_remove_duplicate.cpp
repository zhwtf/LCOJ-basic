'''
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

'''



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
