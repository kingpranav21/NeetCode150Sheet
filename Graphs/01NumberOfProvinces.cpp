class Solution {
public:
    // using matrix only
    // TC-O(n^2), SC-O(n)
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n = isConnected.size();
    //     vector<int>visited(n,0);
    //     int counter = 0;
    //     for(int i=0;i<n;i++){
    //         if(!visited[i]){
    //             counter++;
    //             dfs(i, isConnected, visited);
    //         }
    //     }
    //     return counter;
    // }
    // void dfs(int node, vector<vector<int>>&isConnected, vector<int>&visited){
    //     visited[node] = 1;

    //     for(int j=0;j<isConnected.size();j++){
    //         if(isConnected[node][j] == 1 && !visited[j]){
    //             //if it is connected
    //             //we are not checking the self connected part , because
    //             visited array handles that

    //             dfs(j, isConnected, visited);
    //         }
    //     }
    // }

    // using adjList
    // TC-O(n^2), SC-O(n+E)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        // creating adj list
        vector<vector<int>>adjList(size); // list of vectors
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    // not self connected
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        // j   0   1   2
        // i
        // 0  1   1   0
        // 1  1   1   0
        // 2  0   0   1

        // 0 -> {1}
        // 1 -> {0}
        // 2 -> {}
        vector<int> visited(size, 0);
        int count = 0;
        for (int i = 0; i < size; i++) {
            if(!visited[i]){
                count++;
                bfs(i, visited, adjList);
            } 
    }
    return count;
    }
    void bfs(int node, vector<int>&visited, vector<vector<int>>adj){
        visited[node] = 1;
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto it : adj[front]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
    }
};