class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        priority_queue<int> pq;
        int cur = startFuel;
        int ans = 0;
        int ind = 0;
        while(cur < target)
        {
            while(ind < n && cur >= stations[ind][0]){
                pq.push(stations[ind][1]);
                ind++;
            }
            if(pq.empty()) return -1;
            cur += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};