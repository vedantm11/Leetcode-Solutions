class Solution {
public:
   bool isReplaceable(string s,string stamp,int m)
{
    for(int i=0;i<m;i++)
    {
        if(s[i]!=stamp[i] && s[i]!='?')
        {    
            return false;
        }
    }
    
    return true;
}
vector<int> movesToStamp(string stamp, string target) {
    
    
    vector<int> v,result;;
    int n=target.size();
    int m=stamp.size();
    string s="";
    for(int i=0;i<n;i++)
    {
        s+='?';
    }
    
    while(s!=target)
    {
        int flag=0;
        for(int i=0;i<=n-m;i++)
        {
            if(find(v.begin(),v.end(),i)!=v.end())
                continue;
            
            if(isReplaceable(target.substr(i,m),stamp,m))
            {
                
                v.push_back(i);
                string temp="";
                for(int i=0;i<m;i++)
                {
                    temp+='?';
                }
                target.replace(i,m,temp);
                result.push_back(i);
                flag=1;
            }
        }
        if(flag==0)
        {
            vector<int> a;
            return a;
        }
            
            
    }
    reverse(result.begin(),result.end());
    return result;
    
}
};