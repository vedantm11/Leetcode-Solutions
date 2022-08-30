class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        int sum = 0;
        vector<int> st = {INT_MAX};
        for(auto& x : arr) {
            while(st.back() <= x) {
                int small = st.back();
                st.pop_back();
                sum += small * min(st.back(), x);
            }
            st.push_back(x);
        }
        for(int i = st.size()-1; i >= 2; --i) {
            sum += st[i] * st[i-1];
        }
        return sum; 
    }
};