class Solution {
public:
    int trap(vector<int>& height) {
        // returning 0 if none or only one hieght is recorded
        if(height.size() < 2) return 0;

        // keeping track of previous boundaries
        vector<int> checkp;

        int l = 0, r = 0;
        int ground = 0;
        int area = 0;
        while(r < height.size()-1) {
            if(height[r] > height[r+1]) {
                checkp.push_back(l);
                l = r;
                ground = height[++r];
            }
            else if(height[r] == height[r+1]) {
                r++;
            }
            else {
                while(checkp.size() != 0) {
                    // cout << "added: " << (min(height[l], height[r+1]) - ground) * (r-l) << " Blocks on L / R: " << l << "/" << r << endl;
                    area += (min(height[l], height[r+1]) - ground) * (r-l);
                    ground = min(height[l], height[r+1]);
                    if(height[r+1] >= height[l]) {
                        l = checkp[checkp.size()-1]; checkp.pop_back();
                    }
                    else break;
                }
                r++;
            }
            // cout << "l: " << l << " r: " << r << endl;
        }
        return area;
    }
};
