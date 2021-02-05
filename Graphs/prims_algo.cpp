/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
1 <= Wi <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getMinVertex(bool* visited, int* weight, int n) {
    int minVertex = -1;
    for (int i=0; i<n; i++) {
        if (!visited[i] && ( (minVertex == -1) || (weight[minVertex] > weight[i]))) {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int** edges, int v, int e) {
    bool* visited = new bool[v]();
    int* weights = new int[v];
    int* parent = new int[v];
    for (int i=0; i<v; i++) {
        weights[i] = INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;
    
    for(int i=0; i<v-1; i++) {
        // get min vertex i.e get vertex which has minimum weight
        // it should be unvisited
        int minVertex = getMinVertex(visited, weights, v);
        visited[minVertex] = true;
        // check all the neighbour od minVertex
        // update the weight and parent according to that
        for (int j=0; j<v; j++) {
            if (!visited[j] && edges[minVertex][j] != 0) {
                if (weights[j] > edges[minVertex][j]) {
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    // print the vertices with weight
    for (int i=1; i<v; i++) {
        if (parent[i] < i) {
         	cout << parent[i] << " " << i << " " << weights[i] << endl;   
        } else {
            cout << i << " " << parent[i] << " " << weights[i] << endl;
        }
    }
}

int main() {
    int v,e;
    cin >> v >> e;
    int** Edge = new int*[v];
    for (int i=0; i<e; i++) {
        Edge[i] = new int[v];
        for (int j=0; j<v; j++) {
            Edge[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        Edge[v1][v2] = w;
        Edge[v2][v1] = w;
    }
    
    prims(Edge, v, e);
    
    return 0;
}
