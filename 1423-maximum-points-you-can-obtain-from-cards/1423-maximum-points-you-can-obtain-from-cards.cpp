class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int mx=INT_MIN;
        int cursum=0;
        for(int i=0;i<k;i++) cursum+=cardPoints[i];
        mx=max(mx,cursum);
        int l=k-1;
        int r=cardPoints.size()-1;
        for(int i=0;i<k;i++){
            cursum=cursum-cardPoints[l--]+cardPoints[r--];
            mx=max(cursum,mx);
        }
        return mx;
    }
};