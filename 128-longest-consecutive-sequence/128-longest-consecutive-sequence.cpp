class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)    return 0;
        int ans=INT_MIN;
        unordered_set<int> s;
        for(int i=0;i<n;i++)    s.insert(nums[i]);
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1)==s.end()){
                int count=0;
                int num=nums[i];
                while(s.find(num)!=s.end()){
                    num++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
        
    }
};