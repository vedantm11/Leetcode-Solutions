class Solution {
public:
    
    int fib(int n) {
     int fib[31];
     fib[0]=0;
     fib[1]=1;
     int i=2;
     while(i<=n){
         fib[i]=fib[i-1]+fib[i-2];
         i++;
     }
     return fib[n];   
     
    }
};