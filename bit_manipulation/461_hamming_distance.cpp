//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int j, k;
        for (int i = 0; i < 32; i++){
            j = x & 1;
            k = y & 1;
            if (j != k){
                count++;
            }
            x = x>>1;
            y = y>>1;
        }
        return count;
    }
};

//other solution
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};
