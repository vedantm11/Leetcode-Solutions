class Solution {
public:
    int uniquePaths(int m, int n) {
     int ts=m+n-2;
     int nr=m-1;
     double res=1; 
     for(int i=1;i<=nr;i++){
         res=res*(ts-nr+i)/i;
     }
     return (int)(res);   
    }
};