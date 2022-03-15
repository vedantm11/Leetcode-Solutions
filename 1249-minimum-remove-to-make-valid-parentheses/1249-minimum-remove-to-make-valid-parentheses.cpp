class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stk;
        string sol = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                continue;
            }
            else {
                if (s[i] == '(') {
                    stk.push(make_pair(s[i], i));
                }
                else {
                    if (stk.size() != 0 && stk.top().first == '(') {
                        s[i] = '1';
                        s[stk.top().second] = '0';
                        stk.pop();
                    }
                }
            }
         }
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' || s[i] == '(') {
                continue;
            }
            else {
                if (isalpha(s[i])) {
                    sol += s[i];
                }
                else {
                    if (s[i] == '1') {
                        sol += ')';
                    }
                    else {
                        sol += '(';
                    }
                }
            }
        }
        
        return sol;
        
        
    
        
    }
};