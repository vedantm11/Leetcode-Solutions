class Solution {
public:
    int mod = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map <int, long> mp;
        mp[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++){
            long c = 1;
            for(auto j : mp){
                int fac1 = j.first;
                if(arr[i] % fac1 == 0 && mp.find(arr[i] / fac1) != mp.end()){
                    c += mp[fac1] * mp[arr[i] / fac1];
                }
            }
            mp[arr[i]] = c;
        }
        int ans = 0;
        for(auto i : mp){
            ans = (ans + i.second) % mod;
        }
        return ans;
    }
};