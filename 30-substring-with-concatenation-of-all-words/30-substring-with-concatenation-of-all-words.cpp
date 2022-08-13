class Solution {
public:
    bool checkSubstring(string s, unordered_map<string,int> mp, int wl){
        for(int i = 0;i < s.size(); i+=wl){
            string temp = s.substr(i,wl);
            if(mp.find(temp) != mp.end()){
                if(--mp[temp] == -1) return false;
            }
            else return false;    
        }
        
        
        return true;
        
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int wl = words[0].size();
        int awl = words.size()*wl;
        unordered_map<string,int> mp;
        vector<int> ans;
        for(auto i : words) mp[i]++;
        int i = 0;
        while(i + awl <= n){
            if(checkSubstring(s.substr(i,awl),mp,wl)) ans.push_back(i);
            i++;
        }
        
        return ans;
        
        
    }
};