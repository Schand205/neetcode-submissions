class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IGNORE: turns off leetcodes I/O-Overhead 
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int i = 0;
        int max = 0;
        unordered_set<int> hash;

        for(int j = 0; j < s.length(); ++j) {
            while(hash.count(s[j])) {
                hash.erase(s[i++]);
            }
            hash.insert(s[j]);
            if(hash.size() > max) max = hash.size();
        }
        
        return max;
    }
};
