class Solution {
public:
    vector<string> ans;
    
    void generateParanthesisHelper(string s,int o,int c,int n)
    {
        if(o==n && c==n)    ans.push_back(s);
        else if(o==n) {
            s+=')';
            generateParanthesisHelper(s,o,c+1,n);
        }
        else if(o<n && c<n && o==c)
        {
                s+='(';
            generateParanthesisHelper(s,o+1,c,n);
        }
        else if(o<n && c<n){
            string s1=s;
                s+='(';
            generateParanthesisHelper(s,o+1,c,n);
            s1+=')';
            generateParanthesisHelper(s1,o,c+1,n);
            
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        generateParanthesisHelper("(",1,0,n);
        return ans;
        
    }
};