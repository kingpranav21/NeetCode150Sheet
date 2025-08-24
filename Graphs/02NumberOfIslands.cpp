//TC->O(n*m), SC->O(n*m)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n, vector<int>(m,0));

        int islands = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    islands++;
                    bfs(i,j, visited, grid);
                }
            }
        }
        return islands;
    }
    bool checkinBound(int i, int j, vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        return ((i<n && i>=0 && j<m && j>=0));
    }
    void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid){
        visited[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();

            vector<vector<int>>directions{{-1,0}, {1,0}, {0,-1}, {0,1}};
            for(int i=0;i<4;i++){
                    int new_row = front.first + directions[i][0];
                    int new_col = front.second + directions[i][1];

                    if(checkinBound(new_row, new_col, grid) && !visited[new_row][new_col] && grid[new_row][new_col]=='1'){
                        visited[new_row][new_col]=1;
                        q.push({new_row, new_col});
                    }
            }
        }
    }
};