class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i=0;i<n;i++) ans+='a';
        int i=n-1;
        k=k-n;
        while(k>0){
            if(k>25){
                ans[i]=(char)('a'+ 25);
                k=k-25;
            }
            else{
                ans[i]=(char)('a'+ k);
                k=0;
            }
            i--;
        }
        return ans;
        
    }
};