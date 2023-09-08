/* I will be using Priority queue from STL as it is much easier to implement and understand it

Reference video = G-45. Prim's Algorithm - Minimum Spanning Tree - C++ and Java

vertex = node & vice versa

Note - This code only prints the minimum cost and NOT the mst currently
 */

#include <iostream>
#include <queue>
using namespace std;



int prims_Spanning_Tree(int V,vector<vector<int>> adj[]){
    // Priority Queue which holds pairs of integers and sorts in ascending order based on the first integer in each pair
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(V,0); // Visted array with inital val = 0
    int sum = 0;

    // weight,node
    pq.push({0,0});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if(vis[node] == 1)
            continue;
        
        sum += wt;
        vis[node] = 1;

        // Going to the adjacent edges and checking if they are not visited and adding them to the priority queue

        for(auto it: adj[node]){
            int adjNode = it[0];
            int eWt = it[1];

            if(!vis[adjNode])
                pq.push({eWt,adjNode});
        }

    }

    return sum;
}

int main(){
    // No. of vertices
    const int V = 5; 

    // Store in {vertex1,vertex2,weight} form
    vector<vector<int>>edges = {{0,1,2},{0,2,1},{1,2,1},{2,3,2},{3,4,1},{4,2,2}};

    // Adjacency list
    vector<vector<int>> adj[V];

    // Initalizing our adjacency list with a node and it's adjacent neighbours
    for(auto it:edges){
        vector<int>tmp(2);

        // Adding the 2nd node and weight with the 1st node
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        // Adding the 1st node and weight with the 2nd node
        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }
int sum = prims_Spanning_Tree(V,adj);

cout << "Sum of the MST using Prim's algo is " << sum;

}