class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // IGNORE: turns off leetcodes I/O-Overhead 
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int max = 0;
        int curr = 0;
        for(int i = 0; i < prices.size()-1; ++i) {
            if(curr < 0) curr = 0;
            curr += prices[i+1] - prices[i];
            if(curr > max) max = curr;
        }
        return max;
    }
};
