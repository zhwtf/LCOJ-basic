'''
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6
'''

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using dynamic programming, store the subproblems' results in dp[];
        int n = nums.size();
        int *dp = new int[n];
        dp[0] = nums[0];
        int maxnum = nums[0];

        for(int i = 1; i < n; i++){
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1]:0);
            maxnum = max(maxnum, dp[i]);
        }
        return maxnum;

    }
};

//Idea is very simple. Basically, keep adding each integer to the sequence until the sum drops below 0.
//If sum is negative, then should reset the sequence.
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans=A[0],i,j,sum=0;
        for(i=0;i<n;i++){
            sum+=A[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;
    }
};
