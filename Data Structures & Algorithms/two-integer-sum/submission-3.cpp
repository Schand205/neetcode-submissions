class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = hash.find(complement);
            if(it != hash.end()) {
                ret.push_back(it->second);
                ret.push_back(i);
                return ret;
            }
            else {
                hash[nums[i]] = i;
            }
        }
    }
};
