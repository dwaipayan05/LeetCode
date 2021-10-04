class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>>v(r+2, vector<int>(c+2,0));
        
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                v[i][j] = grid[i-1][j-1];
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <=c; j++)
            {
                int n = 0;
                if(v[i][j]==1)
                {
                    if(v[i-1][j])n++;
                    if(v[i][j-1])n++;
                    if(v[i+1][j])n++;
                    if(v[i][j+1])n++;
                    ans += 4 - n;
                }
                
                
            }
        }
        
        
        return ans;
    }
};