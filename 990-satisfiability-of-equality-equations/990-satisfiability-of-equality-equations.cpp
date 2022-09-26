class Solution {
    
public:
    int uf[26];
    int union_find(int val)
    {
        if(val != uf[val]) uf[val] = union_find(uf[val]);
        return uf[val];
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; i++) uf[i] = i;
        
        for(auto i : equations){
            if(i[1] == '=') uf[union_find(i[3] - 'a')] = union_find(i[0] - 'a');
        }
        for(auto i : equations){
            if(i[1] == '!' && (union_find(i[3] - 'a') == union_find(i[0] - 'a'))) return false;
        }
        return true;
        
    }
};