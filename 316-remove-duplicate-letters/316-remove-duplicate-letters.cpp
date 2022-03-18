class Solution {
public:
    string removeDuplicateLetters(string s) {
         string ans="";
        int freq[256]={0};
        bool visited[256]={0};
        for(char & c:s)
            freq[c]++;
        for(char& c:s){
            freq[c]--;
            if(visited[c])
                continue;
            while(c<ans.back()&&freq[ans.back()]){
                visited[ans.back()]=false;
                ans.pop_back();
            }
            visited[c]=true;
            ans+=c;
        }
        return ans;
        
    }
};