#include <iostream>
using namespace std;

bool DFS(int** edges, int n, int startV, bool* visited, int v2) {
	//base case
	//check if both vertcies are adjacent or not
    if (edges[startV][v2] == 1) {
        return true;
    }
    visited[startV] = true;
    
    for (int i=0; i<n; i++) {
        if (i == startV) {
            continue;
        }
        
        if (edges[startV][i] == 1 && !visited[i]) {
            return DFS(edges, n, i, visited, v2);
        }
    }
    return false;
}

int main() {
    // n is number of vertices and e is number of edges
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
        // f and s denotes edge between two vertices
        int f,s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    bool* visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }
    
    bool result = DFS(edges, n, v1, visited, v2);
    result == 1 ? cout << "true" << endl : cout << "false" << endl;
    
}
