// Undirected Graph Cycle
// Difficulty: Medium
// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not. The graph can have multiple component.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true

#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int>&visited, vector<vector<int>>&edges, int parentIdx){
    visited[i]=1;

    for(auto adjNodeIdx : edges[i]){
        if(!visited[adjNodeIdx]){
            if(dfs(adjNodeIdx, visited, edges, i))return true;
        }else if(i!=adjNodeIdx){
            return true;
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
            if(dfs(i, visited, edges, -1)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n =4;
    vector<vector<int>>edges = {{0,1},{0,2},{1,2},{2,3}};

    cout<<detectCycle(n, edges);
}