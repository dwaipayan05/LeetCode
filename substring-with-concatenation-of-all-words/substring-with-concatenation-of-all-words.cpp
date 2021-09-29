class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if(s.length() == 0 || words.size() == 0)
            return {};
        
        map<string,int>mp;
        
        for(auto s : words)
            mp[s]++;
        
        vector<int>res;
        
        int concatLen = words.size()*words[0].length();
        int wordLen = words[0].length();
        int wordCnt = words.size();
        
        if(concatLen > s.length())
            return {};
        
        
        for(int i = 0; i <= s.length() - concatLen ; i++)
        {
            map<string,int>wordsSeen;
            
            for(int j = 0; j < wordCnt; j++)
            {
                int wordIdx = i + j*wordLen;
                string currWord = s.substr(wordIdx, wordLen);
                
                if(mp.find(currWord) == mp.end())
                    break;
                
                wordsSeen[currWord]++;
                
                if(wordsSeen[currWord] > mp[currWord])
                    break;
                
                
                if(j+1 == wordCnt)
                    res.push_back(i);
                
            }           
            
        }
        
        
        return res;
    }
};