//using set
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s(nums1.begin(), nums1.end());
    vector<int> out;
    for (int x : nums2)
        if (s.erase(x))
            out.push_back(x);
    return out;
}

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};

// brute force approach
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int c1 = nums1.size();
        int c2 = nums2.size();
        vector<int> result;
        for (int i = 0; i < c1; i++){
            for (int j = 0; j < c2; j++){
                if (nums1[i] == nums2[j] && find(result.begin(), result.end(), nums2[j]) == result.end()){
                    result.push_back(nums2[j]);
                    break;
                }
            }
        }
        return result;
    }
};
