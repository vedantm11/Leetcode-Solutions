class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for( int i = 0; i < s1.size(); i++){
            if(s1[i] == 'x' && s2[i] == 'y') xy++;
            if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }
        if((xy % 2 + yx % 2) % 2 != 0) return -1;
        int ans = 0;
        ans+= xy / 2 + yx / 2 + xy % 2 + yx % 2;
        return ans;
        
    }
};