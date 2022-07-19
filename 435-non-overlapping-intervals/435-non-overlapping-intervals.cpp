class Solution {
public:
    
    static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[1]<v2[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int last = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(last<=intervals[i][0]) last=intervals[i][1];
            else    ans++;
        }
        return ans;
    }
};