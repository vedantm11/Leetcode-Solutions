class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long ans;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long mxh=horizontalCuts[0];
        long long mxv=verticalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++) mxh=max(mxh,(long long)horizontalCuts[i]-horizontalCuts[i-1]);
        for(int i=1;i<verticalCuts.size();i++) mxv=max(mxv,(long long)verticalCuts[i]-verticalCuts[i-1]);
        mxh=max(mxh,(long long)h-horizontalCuts[horizontalCuts.size()-1]);
        mxv=max(mxv,(long long)w-verticalCuts[verticalCuts.size()-1]);
        return (mxh*mxv)%1000000007;
    }
};