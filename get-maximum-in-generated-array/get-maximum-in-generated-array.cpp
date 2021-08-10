class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int>v(n+1);
        
        int res = INT_MIN;
        for(int i = 0 ; i <= n ; i++)
        {
            if(i == 0)
            {
                v[i] = 0;
                res = max(v[i], res); 
            }
            else if (i == 1)
            {
                v[i] = 1;
                res = max(v[i], res);
            }
            else
            {
                if(i%2 == 0)
                {
                    v[i] = v[i/2];
                    res = max(v[i], res);
                }
                else
                {
                    v[i] = v[(i-1)/2+1] + v[(i-1)/2];
                    res = max(v[i], res);
                }
            }
        }
        
        
        return res;
    }
};