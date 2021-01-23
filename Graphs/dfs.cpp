//  https://ide.geeksforgeeks.org/y8tmkaAGQw

// DFS implementaion using adjacancey matrix

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int** edges, int n, int startV, bool* visited) {
    cout << startV << endl;
    visited[startV] = true;
    
    for (int i=0; i<n; i++) {
        // i think it's case of self edge like A to A
        if (i == startV) {
            continue;
        }
        // if it has some adjancey list then
        if (edges[startV][i] == 1) {
            // check if this vertices already visited
            if (visited[i]) {
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

int main() {
	int n, e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i=0; i<n; i++) {
	    edges[i] = new int[n];
	    for (int j=0; j<n; j++) {
	        edges[i][j] = 0;
	    }
	}
	
	for (int i=0; i<e; i++) {
	    int f, s;
	    cin >> f >> s;
	    edges[f][s] = 1;
	    edges[s][f] = 1;
	}
	bool* visited = new bool[n];
	for (int i=0; i<n; i++) {
	    visited[i] = false;
	}
	print(edges, n, 0, visited);
	delete [] visited;
	for (int i=0; i<n; i++) {
	    delete [] edges[i];
	}
	delete [] edges;
	return 0;
}
