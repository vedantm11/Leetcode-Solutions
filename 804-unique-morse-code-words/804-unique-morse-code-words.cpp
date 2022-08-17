class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
       map<string,int> ans;
        for(int i = 0; i< words.size(); i++){
            string temp = "";
            string cur = words[i];
            for(int j = 0; j < cur.size(); j++) temp += arr[cur[j] - 'a'];
            ans[temp]++;
        }
        return ans.size();
        
    }
};