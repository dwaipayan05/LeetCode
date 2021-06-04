class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int small = INT_MAX;
        int large = INT_MIN;
        
        for(auto x: nums)
        {
            small = min(small, x);
            large = max(large, x);
        }
        
        
        return (small + k >= large-k) ? 0 : large-k - small-k;
    }
};