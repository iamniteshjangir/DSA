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

struct Edges {
    int src;
    int dest;
    int weight;
};

bool sorter(Edges a, Edges b) {
    if (a.weight < b.weight) {
        return true;
    }
    return false;
}

int get_parent(int current, int* parent) {
    while(current != parent[current]) {
        current = parent[current];
    }
    return current;
}

int main() {
    int v,e;
    cin >> v >> e;
    Edges* edges = new Edges[e];
    for (int i=0; i<e; i++) {
        int s,d,w;
        cin >> s >> d >> w;
        edges[i].src = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }
//     need to sort edges as per weight
    sort(edges, edges+e, sorter);
    int* parent = new int[v];
    for (int i=0; i<v; i++) {
        parent[i] = i;
    }
    int count = 0, i=0;
    Edges* output = new Edges[v-1];
    while(count < v-1) {
        Edges current = edges[i];
        int first_parent = get_parent(current.src, parent);
        int second_parent = get_parent(current.dest, parent);
        if (first_parent != second_parent) {
            output[count++] = current;
            parent[first_parent] = second_parent;
        }
        i++;
    }
    for (int i=0; i<v-1; i++) {
        if (output[i].src < output[i].dest) {
            cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
        } else {
            cout << output[i].dest << " " << output[i].src << " " << output[i].weight << endl;
        }
    }
}
