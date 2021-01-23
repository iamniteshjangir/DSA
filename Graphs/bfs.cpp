#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int** edges, int n, int startV, bool* visited, queue<int> q) {
    
    visited[startV] = true;
    q.push(startV);
    
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
    	cout << temp << " ";
        
        for (int i=0; i<n; i++) {
        	if (i == temp) {
                continue;
            }
            if(edges[temp][i] == 1) {
                if (visited[i]) {
                    continue;
                }
                visited[i] = true;
                q.push(i);
            }
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
            edges[i][j] == 0;
        }
    }
    
    for (int i=0; i<e; i++) {
        int f,s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    bool* visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }
    queue<int> q;
    for (int i=0; i<n; i++) {
     	if (!visited[i]) {
            print(edges, n, i, visited, q);
        }   
    }
    
}
