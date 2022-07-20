class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
       int ans=0;
        unordered_map<string,int> mp;
        for(auto i : words) mp[i]++;
        
        for(auto i : mp){
            string temp = i.first;
            int l1 = 0, l2 = 0;
            while(l1<s.length() && l2<temp.length()){
                if(s[l1] == temp[l2]) l2++;
                l1++;
            }
            if(l2==temp.length()) ans+=i.second;
        }
        return ans;
        
        
    }
};