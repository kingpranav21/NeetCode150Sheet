// Time Complexity → O(n × m)

// Space Complexity → O(n × m)

class Solution {
public:
    vector<vector<int>>dist{{-1,0},{1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<pair<int,int>, int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        int time = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                   q.push({{i,j}, 0});
                   visited[i][j] = 2;
                }else{
                    visited[i][j]=0;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second; 
            time = max(time, t);
            q.pop();

            for(int i=0;i<4;i++){
                int new_row = row + dist[i][0];
                int new_col = col + dist[i][1];

                if(new_row>=0 && new_row<grid.size() && new_col>=0 && new_col<grid[0].size() && grid[new_row][new_col]==1 && !visited[new_row][new_col]){
                    q.push({{new_row, new_col},t+1});
                    visited[new_row][new_col]=2;
                    fresh --;
                }
            }
        }
        return (fresh>0) ? -1 : time;
    }
};