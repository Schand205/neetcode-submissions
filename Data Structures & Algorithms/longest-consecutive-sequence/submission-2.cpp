class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> sort;
        for(int i = 0; i < nums.size(); ++i) {
            sort.insert(nums[i]);
        }

        if(sort.size() == 0) return 0;
        if(sort.size() == 1) return 1;

        int max = 0; 
        int count = 1;
        auto iter = (sort.begin());
        int prev = *(iter++);
        for(; iter != sort.end(); iter++) {
            if(*iter == prev+1) {
                count++;
            }
            else {
                count = 1; 
            }
            if (count > max) max = count;
            prev = *iter;
        }
        return max;
    }
};
