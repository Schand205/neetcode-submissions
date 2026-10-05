class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0;
        int max = 0;
        int curr = 0;
        while(i < prices.size() - 1) {
            if(curr < 0) curr = 0;
            curr += prices[i+1] - prices[i];
            if(curr > max) max = curr;
            i++;
        }
        return max;
    }
};
