class Solution {
public:

    string encode(vector<string>& strs) {
        string enc;
        if(strs.begin() == strs.end()) return "";
        for(auto& s : strs) {
            enc += to_string(s.size()) + "," + s;
        }
        return enc;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};

        vector<string> ret;

        while(s.size() > 0) {
            int i = s.find(',');
            string temp = s.substr(0, i);
            int length = 0;
            for(i = 0; i < temp.size(); ++i) length = length * 10 + (s[i] - '0');

            s = s.substr(i+1);
            ret.push_back(s.substr(0, length));
            s = s.substr(length);
        }
        return ret;
    }
};
