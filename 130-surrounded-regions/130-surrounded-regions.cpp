class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int r, int c)
    {
        if(r < 0 or c < 0 or r == board.size() or c == board[0].size() or board[r][c] != 'O')
            return;
        
        board[r][c] = 'T';
        dfs(board,r+1,c);
        dfs(board,r-1,c);
        dfs(board,r,c+1);
        dfs(board,r,c-1);
    }
    
    void solve(vector<vector<char>>& board) {
        
        int R = board.size(), C = board[0].size();
        
        for(int i=0; i<R; i++)
        {
            if(board[i][0] == 'O') dfs(board,i,0);
            if(board[i][C-1] == 'O') dfs(board,i,C-1);
        }
        
        for(int j=0; j<C; j++)
        {
            if(board[0][j] == 'O') dfs(board,0,j);
            if(board[R-1][j] == 'O') dfs(board,R-1,j);
        }
        
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(board[i][j] == 'T')
                {
                    board[i][j] = 'O';   
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};