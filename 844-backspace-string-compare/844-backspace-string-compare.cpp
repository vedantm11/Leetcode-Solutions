class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ns="",nt="";
        int hc=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#') {
                hc++;
                continue;
            }
            if(hc>0) {
                hc--;
                continue;
            }
            else ns+=s[i];
        }
        reverse(ns.begin(),ns.end());
        hc=0;
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='#'){
             hc++;
            continue;
            }    
            if(hc>0) {
                hc--;
                continue;
            }
            else nt+=t[i];
        }
        reverse(nt.begin(),nt.end());
        cout<<ns<<" "<<nt;
        return ns==nt;
    }
};