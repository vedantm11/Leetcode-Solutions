class Solution {
public:
    
    bool static cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0] != b[0]) return a[0] > b[0];
        else return a[1] < b[1]; 
        
        
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans = 0;
        sort(properties.begin(),properties.end(),cmp);
        int mx = INT_MIN;
        for(auto i : properties){
            if(mx > i[1]) ans++;
            else{
                mx = max(mx,i[1]);
            }
            
        }
        
        return ans;
    }
};