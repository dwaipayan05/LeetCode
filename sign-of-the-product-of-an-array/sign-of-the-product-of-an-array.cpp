class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int minus = 0;
        for(auto x : nums)
        {
            if(x == 0)
                return 0;
            else if (x < 0)
                minus++;
        }
        
        return minus%2==0 ? 1 : -1;
    }
};