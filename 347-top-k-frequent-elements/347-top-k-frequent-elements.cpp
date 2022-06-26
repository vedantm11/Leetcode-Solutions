class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==k) return nums;
        map<int,int> mp;
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto i : nums) mp[i]++;
        for(auto i : mp){
            pq.push({i.second,i.first});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};