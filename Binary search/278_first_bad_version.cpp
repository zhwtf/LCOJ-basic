// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int last = n;
        int first = 1;
        int mid;
        while (first < last){
            mid = first + (last - first)/2; //to avoid overflow
            bool test = isBadVersion(mid);
            if (test == true){
                last = mid;
            }
            else{
                first = mid + 1;
            }
        }
        return first;/* Because there will alway be a bad version, return first here */
    }
};
