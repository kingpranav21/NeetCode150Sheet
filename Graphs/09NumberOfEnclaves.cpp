class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]){
                        visited[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vector<vector<int>>directions={{-1,0}, {1,0}, {0,1}, {0,-1}};

            for(int i=0;i<4;i++){
                int row_ = row + directions[i][0];
                int col_ = col + directions[i][1];

                if(row_<n && col_<m && row_>=0 && col_>=0 && grid[row_][col_]==1 && !visited[row_][col_]){
                    visited[row_][col_]=1;
                    q.push({row_,col_});
                }
            }
        }

        //now the ones which are left are the islands that are covered by zeros and cannot walk off the boundry
        int landCellsleft = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    landCellsleft++;
                }
            }
        }
        return landCellsleft;
    }
};