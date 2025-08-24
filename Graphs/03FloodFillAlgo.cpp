//TC->O(n × m), SC->O(n × m)
class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc];
        if(startColor == color) return image;
        queue<pair<int,int>>q;
        image[sr][sc] = color;
        
        q.push({sr,sc});
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int _row = front.first + directions[i][0];
                int _col = front.second + directions[i][1];

                if(_row>=0 && _row<n && _col>=0 && _col<m && image[_row][_col]==startColor){
                    image[_row][_col] = color;
                    q.push({_row,_col});
                }
            }
        }
        return image;
    }
};