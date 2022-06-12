class Solution {
public:
    int minOperations(vector<int> &nums, int x)
    {
      int n=nums.size();
        int l=0,r=0;
        int sum=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
         int c=nums[0];
        while(l<n&&r<n){
            if(c<sum-x){
                r++;
                if(r==n)    break;
                c+=nums[r];
            }
            if(c>sum-x){
                c-=nums[l];
                l++;
            }
            if(c==sum-x){
                ans=max(ans,r-l+1);
                r++;
                if(r==n)    break;
                c+=nums[r];
            }
        }
        if(ans==-1) return -1;
        else return n-ans;
    }
};