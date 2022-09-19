class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp; 
        
        for (auto& path : paths) 
        {
            istringstream iss (path); 
            string file; 
            vector<string> files; 
            while (iss >> file) 
                files.push_back(file); 
            
            for (int i = 1; i < files.size(); ++i) 
            {
                int k = files[i].find("("); 
                mp[files[i].substr(k)].push_back(files[0] + "/" + files[i].substr(0, k)); 
            }
        }
        
        vector<vector<string>> ans; 
        for (auto& x: mp) 
        {
            if (x.second.size() > 1) 
            {
                ans.push_back(x.second); 
            }
        }
        return ans; 
        
    }
};