/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
        int src;
        int dest;
        int weight;
};

bool sorter(Edge a, Edge b) {
    return a.weight < b.weight;
}

int getParent(int* parent, int v) {
    if (parent[v] == v) {
        return v;
    }
    return getParent(parent, parent[v]);
}

void kruskal(Edge* edges, int n, int e) {
    // create parent array for storing parents of vertices
    int* parent = new int[n];
    for (int i=0; i<n; i++) {
        parent[i] = i;
    }
    Edge* output = new Edge[n-1];
    // cout << "hi";
    sort(edges, edges+e, sorter);
    
    int count = 0, i = 0;
    while(count < n-1) {
        // get parent of src and dest
        int firstParent = getParent(parent, edges[i].src);
        int secondParent = getParent(parent, edges[i].dest);
        // if both parent not equal then we have to
        // add this edge
        if (firstParent != secondParent) {
            output[count] = edges[i];
            count++;
            parent[firstParent] = secondParent;
        }
        i++;
    }
    
    for (int i=0; i<n-1; i++) {
        cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
    }
}

int main() {
	int v,e;
	cin >> v >> e;
	Edge* edges = new Edge[e];
	for (int i=0; i<e; i++) {
	    int v1, v2, w;
	    cin >> v1 >> v2 >> w;
	    edges[i].src = v1;
	    edges[i].dest = v2;
	    edges[i].weight = w;
	}
	
	kruskal(edges, v, e);
	return 0;
}
