class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int> nge(10005,0);
        vector<int> ans;
       stack<int> s;
        
       for(int i = 0;i < nums2.size(); i++){
            while(!s.empty() && s.top() <= nums2[i]){
                cout<<s.top()<<endl;
                int temp = s.top();
                s.pop();
                nge[temp] = nums2[i];
          }
          s.push(nums2[i]); 
    }
    while(!s.empty()){
        nge[s.top()] = -1;
        s.pop();
    }    
        
    for(int i = 0; i < nums1.size(); i++) ans.push_back(nge[nums1[i]]);
    
    return ans;    
    }    
};