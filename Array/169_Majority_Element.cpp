//Given an array of size n, find the majority element.
//The majority element is the element that appears more than ⌊ n/2 ⌋ times.

//Hash Table Solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
    }
};

//Randomization
// randomly pick an element and see if it is the majority one.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0;
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++;
            if (counts > n / 2) return candidate;
        }
    }
};
