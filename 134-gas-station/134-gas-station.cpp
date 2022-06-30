class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tc=0;
        int cc=0;
        int ans=0;
        for(int i=0;i<gas.size();i++){
            tc=tc+(gas[i]-cost[i]);
            cc=cc+(gas[i]-cost[i]);
            if(cc<0){
                cc=0;
                ans=i+1;
            }
        }
        if(tc>=0) return ans;
        else return -1;
    }
     
};