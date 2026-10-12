class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // IGNORE: turns off leetcodes I/O-Overhead 
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        /*
        1. Iterate over first window and add to ordered set
        2. shifting over nums always add the new to set and delete the one on the left
        3. always check for the first 

        Test cases:
        - window is equal length to k
        */
        multiset<int> hash;

        for(int i = 0; i < k; ++i) {
            hash.insert(nums[i]);
        }
        //Testcase 1:
        if(nums.size() == k) return {*prev(hash.end())};


        vector<int> ret;
        ret.push_back(*prev(hash.end()));

        int i = 0;
        int j = k;
        while(j < nums.size()) {
            hash.erase(hash.find(nums[i++]));
            hash.insert(nums[j++]);
            ret.push_back(*prev(hash.end()));
        }
        return ret;
    }
};
