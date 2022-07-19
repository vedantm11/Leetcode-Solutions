class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        stack<pair<int,int>> s;
        vector<int> ans(t.size(),0);
        for(int i=0;i<t.size();i++){
            while(!s.empty() && s.top().first<t[i]){
                auto temp=s.top();
                ans[s.top().second]=i-s.top().second;
                s.pop();
            }
            s.push({t[i],i});
        }
        while(!s.empty()){
            auto temp=s.top();
            ans[s.top().second]=0;
            s.pop();
        }
        return ans;
        
    }
};