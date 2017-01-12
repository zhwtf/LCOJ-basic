//Given two arrays, write a function to compute their intersection.
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


vector<int> intersect(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> ctr;
    for (int i : a)
        ctr[i]++;
    vector<int> out;
    for (int i : b)
        if (ctr[i]-- > 0)
            out.push_back(i);
    return out;
}
