class Solution {
public:
    bool isValid(string s) {
        // IGNORE: turns off leetcodes I/O-Overhead 
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if(s.size() % 2 != 0) return false;
        stack<int> st;
        char c;
        for(int i = 0; i < s.size(); ++i) {
            c = s[i];
            switch(c) {
                case ')': 
                    if(st.empty() || st.top() != c-1) return false;
                    else st.pop(); break;
                case ']':
                    if(st.empty() || st.top() != c-2) return false;
                    else st.pop(); break;
                case '}':
                    if(st.empty() || st.top() != c-2) return false;
                    else st.pop(); break;
                default: st.push(c);
            }
        }
        if(st.empty())  return true;
        else            return false;
    }
};
