//Integer square root and using newton's method
// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
// https://en.wikipedia.org/wiki/Newton%27s_method
long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r*r == x;










//wrong solution
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int low = 0;
        int high = num/2;
        int mid;
        while (low <= high){
            mid = low + (high - low)/2;
            if ((mid * mid) == num){
                return true;
            }
            else if ((mid * mid) > num){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};
