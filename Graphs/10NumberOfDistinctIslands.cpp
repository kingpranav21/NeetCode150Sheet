// Number of Distinct Islands
// Difficulty: MediumAccuracy: 62.29%Submissions: 116K+Points: 4Average Time: 20m
// Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

// Example 1:

// Input:
// grid[][] = [[1, 1, 0, 0, 0],
//             [1, 1, 0, 0, 0],
//             [0, 0, 0, 1, 1],
//             [0, 0, 0, 1, 1]]
// Output: 1
// Explanation:
// grid[][] = [[1, 1, 0, 0, 0], 
//             [1, 1, 0, 0, 0], 
//             [0, 0, 0, 1, 1], 
//             [0, 0, 0, 1, 1]]
// Same colored islands are equal. We have 2 equal islands, so we have only 1 distinct island.

// Example 2:

// Input:
// grid[][] = [[1, 1, 0, 1, 1],
//             [1, 0, 0, 0, 0],
//             [0, 0, 0, 0, 1],
//             [1, 1, 0, 1, 1]]
// Output: 3
// Explanation:
// grid[][] = [[1, 1, 0, 1, 1], 
//             [1, 0, 0, 0, 0], 
//             [0, 0, 0, 0, 1], 
//             [1, 1, 0, 1, 1]]
// Same colored islands are equal.
// We have 4 islands, but 2 of them
// are equal, So we have 3 distinct islands.

// Your Task: You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

// Constraints:
// 1 ≤ n, m ≤ 500
// grid[i][j] == 0 or grid[i][j] == 1

// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>> indices;
                    dfs(i, j, visited, grid, i, j, indices);
                    st.insert(indices);
                }
            }
        }
        return st.size();
    }
    void dfs(int row, int col, vector<vector<int>>&visited, vector<vector<int>>&grid, int src_row, int src_col, vector<pair<int,int>>&indices){
        int n = grid.size(), m = grid[0].size();
        visited[row][col] = 1;
        indices.push_back({row-src_row, col-src_col});
        
        vector<vector<int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<4;i++){
            int _row = row + directions[i][0];
            int _col = col + directions[i][1];
            
            if(_row<n &&_row>=0 && _col<m && _col>=0 && !visited[_row][_col] && grid[_row][_col]==1){
                visited[_row][_col]=1;
                dfs(_row, _col, visited, grid, src_row, src_col, indices);
            }
        }
    }
};
