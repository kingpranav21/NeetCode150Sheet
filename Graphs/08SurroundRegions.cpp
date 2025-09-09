//TC->O(n*m), SC->O(n*m)
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>&board, vector<vector<int>>&visited){
        visited[row][col]=1;
    int n = board.size(), m = board[0].size();
        vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<4;i++){
            int _row = directions[i][0] + row;
            int _col = directions[i][1] + col;

            if(_row>=0 && _col>=0 && _row<n && _col<m && !visited[_row][_col] && board[_row][_col]=='O'){
                visited[_row][_col]=1;
                dfs(_row, _col, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(),  m = board[0].size();
        vector<vector<int>>visited(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,board,visited);
            }
            if(!visited[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,visited);
            }
        }

        for(int j=0;j<m;j++){
            if(!visited[0][j] && board[0][j]=='O'){
                dfs(0,j,board, visited);
            }
            if(!visited[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1, j,board, visited);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
