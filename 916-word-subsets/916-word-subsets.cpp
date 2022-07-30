class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<vector<int>> v(words1.size(),vector<int>(26,0)) ;
        for(int i=0;i<words1.size();i++){
            for(int j=0;j<words1[i].length();j++) v[i][words1[i][j]-'a']++;
        }
        vector<int> tempf(26,0);
        for(int j=0;j<words2.size();j++){
            string cur=words2[j];
            vector<int> temp(26,0);
            for(int k=0;k<cur.size();k++) {
                temp[cur[k]-'a']++;
                tempf[cur[k]-'a']=max(tempf[cur[k]-'a'],temp[cur[k]-'a']);
            }
        }
        for(int i=0;i<words1.size();i++){
            bool flag=true;
            for(int k=0;k<26;k++){
                if(tempf[k]>v[i][k]){
                        flag=false;
                        break;
                    }
                }
            if(flag) ans.push_back(words1[i]);
        }
        return ans;
    }
};