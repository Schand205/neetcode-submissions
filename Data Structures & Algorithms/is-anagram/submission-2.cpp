class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        if(s.size() == 0)   return true;

        std::unordered_multiset<char> mySet;
        for(int j = 0; j < s.size(); ++j) mySet.insert(s[j]);

        for(int i = 0; i < t.size(); ++i) {
            auto iter = mySet.find(t[i]);
            if(iter != mySet.end()) {
                mySet.erase(iter);
            }
            else    return false;
        }
        return true;
    }
};
