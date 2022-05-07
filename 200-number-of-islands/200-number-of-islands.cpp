class Solution {
public:
    int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int countIslands = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfsNumberIslands(grid, i, j);
                    countIslands++;
                }
            }
        }
        
        return countIslands;
    }
    
    
    void dfsNumberIslands(vector<vector<char>>& grid, int row, int col)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        grid[row][col] = '0';
        
        for(int i = 0; i < 4; i++)
        {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            
            if(newRow >=0 && newCol >=0 && newRow < m && newCol < n && grid[newRow][newCol] == '1')
                dfsNumberIslands(grid, newRow, newCol);
                
        }
    }
};