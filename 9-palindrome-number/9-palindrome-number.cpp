class Solution {
public:
    bool isPalindrome(int x) {
        string val = to_string(x);
        int n = val.length();
        for(int i = 0;i < n/2; i++){
            if(val[i] != val[n-i-1]) return false;
        }
        
        return true;
        
        
    }
};