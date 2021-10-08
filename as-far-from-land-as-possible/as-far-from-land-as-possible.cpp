class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int maxDist = -1;
        
        vector<vector<int>>dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<vector<int>>q;
        
        int r = grid.size();
        int c = grid[0].size();
        
        
        for(int i = 0 ; i < r; i++)
        {
            for(int j = 0; j < c ; j++)
            {
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }
        
        
        while(!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();
            
            for (auto dir : dirs)
            {
                int nx = curr[0] + dir[0];
                int ny = curr[1] + dir[1];
                
                if(nx < r && nx >= 0 && ny < c && ny >= 0 && grid[nx][ny] == 0)
                {
                    grid[nx][ny] = grid[curr[0]][curr[1]] + 1;
                    q.push({nx,ny});
                    maxDist = max(grid[nx][ny] - 1, maxDist);
                }
            }
        }
        
        
        return maxDist;
    }
};