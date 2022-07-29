class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        map<char,char> m1;
        map<char,char> m2;
        for(auto i : words){
            m1.clear();
            m2.clear();
            bool flag=true;
            for(int j=0;j<pattern.size();j++){
                if(m1.find(pattern[j])==m1.end()) m1[pattern[j]]=i[j];
                if(m2.find(i[j])==m2.end()) m2[i[j]]=pattern[j];
                if(m1[pattern[j]]!=i[j] || m2[i[j]]!=pattern[j]){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
        
    }
};