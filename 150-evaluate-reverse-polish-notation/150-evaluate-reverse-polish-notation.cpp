class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        s.push(stoi(tokens[0]));
        int i = 1;
        while(i < tokens.size())
        {
            if(tokens[i] == "/" || tokens[i]  == "+" || tokens[i] == "*" || tokens[i] == "-")
            {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                if(tokens[i] == "/") num1 /= num2;
                else if(tokens[i] == "*") num1 *= num2;
                else if(tokens[i] == "-") num1 -= num2;
                else num1 += num2;
                s.push(num1);
            }
            
            else s.push(stoi(tokens[i]));
            i++;
        }
        
        return s.top();
        
        
    }
};