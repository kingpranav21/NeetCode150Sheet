#include <iostream>
using namespace std;

bool bfs(int i, vector<int>&visited, vector<vector<int>>&adjList){
    visited[i]=1;
    queue<pair<int,int>>q;
    q.push({1,-1});
    while(!q.empty()){
        int currNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNode : adjList[currNode]){
            if(!visited[adjNode]){
                visited[adjNode]=1;
                q.push({adjNode, currNode});
            }
            else if(adjNode!=parent){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>&edges){
    //first create a graph
    vector<vector<int>>adjList(V+1);
    // V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
    // 0 -> {1,2}
    // 1 -> {0,2}
    // 2 -> {0,1}
    // 3 -> {2}

    // {{1,2}, {0,2}, {0,1}, {2}}

    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int>visited(V+1, 0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            if(bfs(i, visited, adjList)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int V;
    cin>>V;
    vector<vector<int>>edges(V+1);

    for(int i=0;i<V;i++){
        for(int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }

    cout<<isCycle(V, edges);
}