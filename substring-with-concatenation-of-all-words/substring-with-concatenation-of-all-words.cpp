class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if(s.length() == 0 || words.size() == 0 )
            return {};
        
        int n = words[0].size();
        int len = words.size() * words[0].size();
        
        if(len > s.length())
            return {};
        map<string, int>mp;
        for(auto s : words)
            mp[s]++;
        
        vector<int>res;
        
        for(int i = 0; i <= s.length() - len; i++ )
        {
            map<string, int> Seen;
            
            for(int j = 0 ; j < words.size(); j++)
            {
                int wordIndex = i + j*words[0].length();
                string curr_word = s.substr(wordIndex, words[0].length());
                if(mp.find(curr_word) == mp.end())
                    break;            
                Seen[curr_word]++;
                
                if(Seen[curr_word] > mp[curr_word])
                    break;
                
                
                if(j + 1 == words.size())
                    res.push_back(i);
                
            }
        }
        
        
        return res;
        
        
    }
};