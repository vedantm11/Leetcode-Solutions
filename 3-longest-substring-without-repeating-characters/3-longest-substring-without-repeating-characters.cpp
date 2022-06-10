class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)    return 0;
        int l=0;
        int r=0;
        int ans=INT_MIN;
        unordered_map<char,int> m;
        while(r<n)
        {
            if(m.find(s[r])!=m.end())   l=max(m[s[r]]+1,l);
            m[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};