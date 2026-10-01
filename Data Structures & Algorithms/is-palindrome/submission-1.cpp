class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while(r > l) {
            s[r] = tolower(s[r]);
            s[l] = tolower(s[l]);
            if (!isalnum(s[r])) r--;
            else if(!isalnum(s[l])) l++;
            else if(s[r] != s[l]) return false;
            else {
                r--;
                l++;
            }
        }
        return true;
    }
};
