class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int col = 0; col < board.size(); col++){ //moving through first and last row
            DFS(board, col, 0);
            DFS(board, col, board[0].size()-1); 
        }
        
        for(int row = 0; row < board[0].size(); row++){ //moving through first and last col
            DFS(board, 0, row);
            DFS(board, board.size()-1, row); 
        }
        
        for(int col = 0; col < board.size(); col++){
            for(int row = 0; row < board[0].size(); row++){
                if (board[col][row] == 'O'){
                    board[col][row] = 'X';
                }
                if (board[col][row] == '#'){
                    board[col][row] = 'O';
                }
            }
        }
    }
private:
    void DFS(vector<vector<char>>& board, int col, int row){
        if (col >= 0 && row >= 0 && col < board.size() && row < board[0].size() && board[col][row] == 'O'){
            board[col][row] = '#';
            DFS(board, col-1, row);
            DFS(board, col, row-1);
            DFS(board, col+1, row);
            DFS(board, col, row+1);
        }
    }
};
/*
X X X X
X O O X
X X O X
X O X X
*/