//Rotate an array of n elements to the right by k steps.

//use extra space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>copy(nums);
        int size = copy.size();
        int k1 = k % size;
        int m;
        if (k == 0 || k == size) return;
        for (int i = 0; i < size; i++){
            m = (i + k1) % size;
            nums[m] = copy[i];
        }
    }
};

// Start from one element and keep rotating until we have rotated n different elements.
//Time complexity: O(n). Space complexity: O(1).
class Solution
    {
    public:
        void rotate(int nums[], int n, int k)
        {
            if ((n == 0) || (k <= 0))
            {
                return;
            }

            int cntRotated = 0;
            int start = 0;
            int curr = 0;
            int numToBeRotated = nums[0];
            int tmp = 0;
            // Keep rotating the elements until we have rotated n
            // different elements.
            while (cntRotated < n)
            {
                do
                {
                    tmp = nums[(curr + k)%n];
                    nums[(curr+k)%n] = numToBeRotated;
                    numToBeRotated = tmp;
                    curr = (curr + k)%n;
                    cntRotated++;
                } while (curr != start);
                // Stop rotating the elements when we finish one cycle,
                // i.e., we return to start.

                // Move to next element to start a new cycle.
                start++;
                curr = start;
                numToBeRotated = nums[curr];
            }
        }
    };
