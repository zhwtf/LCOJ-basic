class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(auto i:nums2){
            auto pos = find(nums1.begin(), nums1.end(), i);
            if(pos != nums1.end()){
                result.push_back(i);
                nums1.erase(pos);
            }
        }
        return result;
    }
};
