class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0; // starting point
        int j = 0; // end point
        int max = 0;
        int changed = 0; // keeping track of already replaced chars in curren twindow
        while(j < s.size()) {
            char curr = s[i];
            if(s[j] != curr) {
                if(changed == k || j == s.size()- 1) {
                    changed = 0;
                    while(s[++i] == curr);
                    j = i;
                }
                else {
                    changed++;
                }
            }
            if(j - i + k - changed + 1 > max) {
                max = j - i + k - changed + 1;
            }
            j++;
        }
        int s_size = s.size();
        return min(max, s_size);
    }
};
