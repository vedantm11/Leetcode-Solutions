class Solution {
public:
    int valCalc(char c)
    {
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else if(c=='M') return 1000;
        return -1;
    }
    int romanToInt(string s) {
        int ans=0;
        int i=0;
        while(i<s.length())
        {
            if(i==s.length()-1) ans+=valCalc(s[i]);
            else
            {
                if(valCalc(s[i])>=valCalc(s[i+1])) ans+=valCalc(s[i]);
                else{
                    int temp=valCalc(s[i+1])-valCalc(s[i]);
                    ans+=temp;
                    i++;
                }
            }
            i++;
        }
        return ans;
    }
};