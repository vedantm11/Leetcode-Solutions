class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k,0);
        int ans=0;
        freq[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            ans+=freq[rem];
                freq[rem]++;
            
        }
        return ans;
    }
};