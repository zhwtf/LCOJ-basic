class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        if(n == 1) return true;
        return (n%2 == 0) && isPowerOfTwo(n/2);

    }
};

//Power of 2 means only one bit of n is '1',
//so use the trick n&(n-1)==0 to judge whether that is the case
//eg 1000=8  0111=7  8&7 == false; so 8 is power of two
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return !(n&(n-1));
    }
};
