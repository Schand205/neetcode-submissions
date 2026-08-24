class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        if(hash.size() == nums.size())  return false;
        else                            return true;
    }
};