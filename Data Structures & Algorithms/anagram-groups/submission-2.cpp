class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anas;
        unordered_map<string, int> track;

        int j = 0;

        for(auto str : strs) {
            string cpy = str;
            sort(cpy.begin(), cpy.end());
            auto iter = track.find(cpy);
            if(iter != track.end()) {
                anas[iter->second].push_back(str);
            }
            else {  
                vector<string> n;
                n.push_back(str);
                anas.push_back(n);
                track[cpy] = j++;
            }
        }
        return anas;
    }
};
