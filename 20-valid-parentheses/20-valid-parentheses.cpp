class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && s[i]==')' && st.top()=='(') st.pop();
            else if(!st.empty() && s[i]==']' && st.top()=='[') st.pop();
            else if(!st.empty() && s[i]=='}' && st.top()=='{') st.pop();
            else st.push(s[i]);
        }
        if(st.empty()) return true;
        else return false;
    }
};