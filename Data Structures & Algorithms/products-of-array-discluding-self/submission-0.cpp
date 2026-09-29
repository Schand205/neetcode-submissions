class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pro;
        int product = 1;
        int zero_found = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) product *= nums[i];
            else zero_found += 1;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(zero_found) {
                if(nums[i] != 0 || zero_found > 1) pro.push_back(0);
                else if(zero_found < 2) pro.push_back(product);
            }
            else pro.push_back(product/nums[i]);
        }

        return pro;
    }
};
