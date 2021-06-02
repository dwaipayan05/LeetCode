class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<bool>>visited(r, vector<bool>(c,false));
        
        vector<int>rtrav = {1,-1,0,0};
        vector<int>ctrav = {0,0,1,-1};
        
        int ans = 0;
        
        for(int i = 0 ; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    int shape = 0;
                    stack<pair<int,int>>st;
                    st.push(make_pair(i,j));
                    
                    visited[i][j] = true;
                    
                    while(!st.empty())
                    {
                        pair<int,int> top = st.top();
                        st.pop();
                        int rx = top.first;
                        int cx = top.second;
                        shape++;
                        
                        for(int k = 0; k < 4 ; k++)
                        {
                            int nr = rx + rtrav[k];
                            int nc = cx + ctrav[k];
                            
                            if(nr >= 0 && nr < r 
                               && nc >= 0 && nc < c
                                && grid[nr][nc] == 1 && !visited[nr][nc])
                            {
                                st.push(make_pair(nr,nc));
                                visited[nr][nc] = true;
                            }
                        }
                    }
                    
                    ans = max(shape, ans);
                }
            }
        }
        
        
        return ans;
    }
};