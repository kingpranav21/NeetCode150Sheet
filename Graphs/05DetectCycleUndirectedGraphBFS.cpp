// Undirected Graph Cycle
// Difficulty: Medium
// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not. The graph can have multiple component.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true

//first let's create graph out of the edges:
//for graph, we will create adj list

//0->{1,2}
//1->{0,2}
//2->{0,1}
//3->{2}

//{{1,2}, {0,2}, {0,1}, {2}}

//create visited array
// 0 1 2 3
//{0,0,0,0}
//then apply bfs on the adjlist

//if(!visited[0])
//bfs(0, visited, adjList)

// visited[0]=1
// initilize q
// push({0, -1}) //idx of that adj list with its parent 
// q->{{0,-1}}
//while(!q.empty())
//int frontIdx = q.front().first //0
//int ParentIdx = q.front().second //-1

//q.pop()
//for(auto adjNode : adjList[frontIdx]){
 //if(!(visited[adjNode])){
    //visited[adjNode]=1;
    //q.push({adjNode, frontIdx});
 //}
 //else if(ParentIdx!=adjNode){
    // return true
//  }
    // return false;
// }

//Tc-> O(N) + O(2E)
//Sc-> O(N)

class Solution {
private:
bool bfs(int i, vector<int>&visited, vector<vector<int>>&adjList){
        visited[i]=1;
        queue<pair<int,int>>q;
        q.push({i, -1}); //came from nowhere , -1 is the parent node
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjNode : adjList[node]){
                if(!visited[adjNode]){
                    visited[adjNode]=1;
                    q.push({adjNode, node});
                }else if(parent!=adjNode){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>>adjList(V+1); //1 based
        
        for(auto Edges : edges){
            int u = Edges[0];
            int v = Edges[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        
        // 0->{1,0}
        // 1->{0,2}
        // 2->{0,1}
        // 3->{2}
        
        vector<int>visited(V+1,0);
        for(int i=1;i<=V;i++){
            if(!visited[i]){
               if(bfs(i, visited, adjList)){
                   return true;
               }
            }
        }
        return false;
    }
    
    
};

//0 based:

#include <bits/stdc++.h>
using namespace std;
bool bfs(int i, vector<int>&visited, vector<vector<int>>&adjList){
    visited[i]=1;
    queue<pair<int,int>>q;
    q.push({i,-1});

    while(!q.empty()){
        int currIdx = q.front().first;
        int parentIdx = q.front().second;
        q.pop();
        for(auto adjNodeIdx: adjList[currIdx]){
            if(!visited[adjNodeIdx]){
                visited[adjNodeIdx]=1;
                q.push({adjNodeIdx, currIdx});
            }else if(adjNodeIdx!=parentIdx){
                //that means someone has already visited before the actual parent
                //means it is not parent
                return true;
            }
        }
    }
    return false;
}
bool detectCycle(int n, vector<vector<int>>&edges){
    vector<vector<int>>adjList(n);

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(bfs(i, visited, adjList))return true;
        }
    }
    return false;
}
int main(){
    int n = 4;
    vector<vector<int>>edges = {{0,1},{0,2},{1,2},{2,3}};

    cout<<detectCycle(n,edges);
}