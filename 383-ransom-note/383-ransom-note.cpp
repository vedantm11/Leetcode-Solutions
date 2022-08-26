class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> mgz(26,0);
        vector<int> note(26,0);
        
        for (int i = 0; i < magazine.size(); i++) mgz[magazine[i] - 'a']++;
        for (int i = 0; i < ransomNote.size(); i++) note[ransomNote[i] - 'a']++;
        for (int i = 0; i < 26 ; i++){
            if(note[i] > mgz[i]) return false;
        }
        
        
        return true;
    }
};