class Solution {
public:
    void merge(int st,int mid,int en,vector<pair<int,int>> &vp,vector<int> &ans){
        vector<pair<int,int>> temp(en - st + 1);
        int i = st, j = mid+1, k = 0;
        while(i <= mid and j <= en){
            if(vp[i].first <= vp[j].first){
                temp[k++] = vp[j++];
            }else{
                ans[vp[i].second] += en - j + 1;
                temp[k++] = vp[i++];
            }
        }
        while(i <= mid) temp[k++] = vp[i++];
        while(j <= en) temp[k++] = vp[j++];
        
        i=st;
        while(i<=en) vp[i++] = temp[i - st];
    }
    void merge_sort(int st,int en,vector<pair<int,int>> &vp,vector<int> &ans){
        if(st < en){
            int mid = st + (en - st)/2;
            merge_sort(st,mid,vp,ans);
            merge_sort(mid+1,en,vp,ans);
            merge(st,mid,en,vp,ans);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<pair<int,int>> vp;
        for(int i=0;i<nums.size();i++){
            vp.push_back({nums[i],i});
        }
        merge_sort(0,nums.size()-1,vp,ans);
        return ans;
    }
};