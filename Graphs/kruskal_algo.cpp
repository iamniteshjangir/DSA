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
