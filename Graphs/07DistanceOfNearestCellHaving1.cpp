//01 matrix problem
//it is a good practce to not to alter given data

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m,0));
        vector<vector<int>>distance(n, vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    visited[i][j]=1;
                    q.push({{i,j}, 0});
                }else{
                    visited[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            distance[row][col] = steps;
            vector<vector<int>>dist{{-1,0}, {0,-1}, {1,0},{0,1}};
            
            for(int i=0;i<4;i++){
                int _row = dist[i][0]+row;
                int _col = dist[i][1]+col;
                
                if(_row>=0 && _col>=0 && _row<n && _col<m && !visited[_row][_col]){
                    visited[_row][_col]=1;
                    q.push({{_row,_col},steps+1});
                }
            }
        }
        return distance;
    }
};