class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // case nums.size() is 0 or 1
        size_t size = nums.size();
        
        if(size <= 1) {
            return false;
        }

        //find max/min val in nums
        int max, min;
        max = min = nums[0];
        for(int elem : nums) {
            if(elem > max) {
                max = elem;
            }
            if(elem < min) {
                min = elem;
            }
        }
        size_t occ_size = max + 1; // +1 for 0 in array
        if(min < 0) {
            min *= -1;
            occ_size += min; // shifting size to fit negative numbers
        }
        else {
            min = 0;
        }

        //create new array
        vector<bool> occupied(occ_size);
        for(int elem : nums) {
            if(occupied[elem+min] == true) {
                return true;
            }
            else {
                occupied[elem+min] = true;
            }
        }
        //if no duplicate was found
        return false;
    }   
};