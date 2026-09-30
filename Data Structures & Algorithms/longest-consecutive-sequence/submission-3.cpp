class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> sort;
        for(int i = 0; i < nums.size(); ++i) {
            sort.insert(nums[i]);
        }

        if(sort.size() == 0) return 0;
        if(sort.size() == 1) return 1;

        int remaining = sort.size();

        int max = 0; 
        int count = 1;
        auto iter = (sort.begin());
        int prev = *(iter++);

        for(; iter != sort.end(); iter++) {
            if(*iter == prev+1) {
                count++;
            }
            else {
                if (count > max) max = count;
                remaining -= count; 
                if (remaining < max) return max;
                count = 1; 
            }
            prev = *iter;
        }
        if (count > max) max = count;
        return max;
    }
};
