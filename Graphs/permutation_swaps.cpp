/*
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.
Input format:
The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
Output format:
For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N
SAMPLE INPUT
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
SAMPLE OUTPUT
NO 
YES
*/






#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void dfs(vector<int>* edges, int start, bool* visited, unordered_set<int>* component) {
    visited[start] = true;
    component->insert(start);
    for (vector<int>::iterator it=edges[start].begin(); it != edges[start].end(); it++) {
        if (!visited[*it]) {
            dfs(edges, *it, visited, component);
        }
    }
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n) {
    bool* visited = new bool[n]();
    unordered_set<unordered_set<int>*>* components = new unordered_set<unordered_set<int>*>();
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            unordered_set<int>* component = new unordered_set<int>();
            dfs(edges, i, visited, component);
            components->insert(component);
        }
    }
    return components;
}

int main()
{
	int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        int* firstArr = new int[n];
        int* secondArr = new int[n];
        
        for (int i=0; i<n; i++) {
            cin >> firstArr[i];
        }
        
        for (int i=0; i<n; i++) {
            cin >> secondArr[i];
        }
		// build graph
		// array of vectors for adjacancy list
        vector<int>* edges = new vector<int>[n];
        for (int i=0; i<q; i++) {
            int a,b;
            cin >> a >> b;
            edges[a-1].push_back(b-1);
            edges[b-1].push_back(a-1);
        }
		// completed adjacancy list
		// now get all connected components
        unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
		// at this point i have all tha components
        bool flag = true;
        unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
        while(it1 != components->end()) {
            unordered_set<int>* component = *it1;
            unordered_set<int>::iterator it2 = component->begin();
            unordered_set<int>p_index;
            unordered_set<int>q_index;
            while(it2 !=  component->end()) {
                p_index.insert(firstArr[*it2]);
                q_index.insert(secondArr[*it2]);
                it2++;
            }
            if (p_index != q_index) {
                flag = false;
            }
            it1++;
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
	return 0;
}
