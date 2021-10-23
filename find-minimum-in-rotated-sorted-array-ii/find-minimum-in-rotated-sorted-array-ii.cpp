class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int mini = INT_MAX;
        
        for(auto x : nums)
        {
            if(x < mini)
                mini = x;
        }
        
        return mini;
    }
};