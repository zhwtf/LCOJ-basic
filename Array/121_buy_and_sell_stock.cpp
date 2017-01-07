//keep track of the min of price seen so far.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        int sofar_min = INT_MAX;
        int profit = 0;
        for (int price:prices){
            profit = price - sofar_min;
            max_prof = max(profit, max_prof);
            sofar_min = min(price, sofar_min);
        }
        return max_prof;
    }
};
