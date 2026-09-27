class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> hash;
        vector<pair<int, int>> temp;
        
        //counting elements in nums
        for(int i = 0; i < nums.size(); ++i) {
            hash[nums[i]]++;
        }
        
        for(auto iter = hash.begin(); iter != hash.end(); iter++) {
            temp.push_back({iter->second, iter->first});
        }

        sort(temp.begin(), temp.end());

        for(int j = 1; j <= k; ++j) {
            ret.push_back(temp[temp.size() - j].second);
        }

        return ret;
    }
};