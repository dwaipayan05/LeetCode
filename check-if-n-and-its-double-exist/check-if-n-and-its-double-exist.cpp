class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>mp;
        
        for(int i = 0 ; i < arr.size(); i++)
        {
            if(mp.find(2*arr[i])!= mp.end() || (mp.find(arr[i]/2)!= mp.end() && arr[i]%2==0))
                return true;
            mp[arr[i]] = 1;
        }
        
        
        return false;
    }
};