class Solution {
public:
    int getMaxDiff(vector<int>& v, int len)
    {
        sort(v.begin(), v.end());
        
        int maxDiff = v[0];
        
        for(int i = 1; i < v.size(); i++)
        {
            maxDiff = max(maxDiff, v[i] - v[i-1]);
        }
        
        maxDiff = max(maxDiff, len - v.back());
        return maxDiff;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        return (long)getMaxDiff(horizontalCuts,h)*getMaxDiff(verticalCuts,w)%1000000007;
    }
};