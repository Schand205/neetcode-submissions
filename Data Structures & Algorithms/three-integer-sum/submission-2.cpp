class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        for(int i = 0; i < nums.size()-2; ++i) {
            while(i > 0 && nums[i] == nums[i-1] && i < nums.size()-2) i++;
            int base = nums[i];
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                int sum = base + nums[l] + nums[r];
                if(sum > 0) r--;
                else if(sum < 0) l++;
                else {
                    ret.push_back({base, nums[l], nums[r]});
                    l++; r--;
                    while(l<nums.size()-1 && nums[l] == nums[l-1]) l++;
                }
            }
        }
        return ret;
    }
};
