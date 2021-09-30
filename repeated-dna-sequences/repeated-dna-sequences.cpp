class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10)
            return {};
        
        if(s.length() == 10)
            return {};
        
        int start = 0;
        
        map<string,int>mp;
        
        vector<string>res;
        while(start <= s.length() - 10)
        {
            string curr_s = s.substr(start, 10);
            cout << curr_s << endl;
            mp[curr_s]++;
            start++;
        }
        
        
        for(auto s : mp)
        {
            if(s.second > 1)
                res.push_back(s.first);
        }
        
        return res;
            
        
        
        
        
            
    }
};

//A A A A A A A A A A A A A
//1