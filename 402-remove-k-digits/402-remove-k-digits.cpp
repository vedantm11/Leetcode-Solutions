class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        k=num.size()-k;
        cout<<k;
        vector<char> ans;
        for(int i=0;i<num.size();i++){
            while(!ans.empty() && ans.back()>num[i] && ans.size()-1+num.size()-i>=k) ans.pop_back();
            if(ans.size()<k) ans.push_back(num[i]);
        }
        string newans;
        int flag=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>'0') {
                flag=1;
                newans+=ans[i];
            }
            if(ans[i]=='0'){
                if(flag) newans+=ans[i];
            }
        }
        if(newans.size()==0) return "0";
        return newans;
    }
};