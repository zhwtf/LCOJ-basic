//key: using xor to cancel same numbers A^B^A = B
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            result ^= nums[i];
        }

        return result;
    }
};



// time exceeds
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        auto it1 = nums.begin();
        auto i = nums.begin();
        while(it1 < nums.end()){
            num = *it1;
            nums.erase(it1);
            auto f = find(nums.begin(), nums.end(), num);
            if(f == nums.end()){
                return num;
            }
            nums.erase(f);
            it1 = nums.begin();

        }
        return num;
    }
};
