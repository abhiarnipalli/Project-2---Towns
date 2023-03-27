//
// Created by Abhlash Arnipalli on 3/14/23.
//
#include "MyGraph.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//Constructor to create a graph with n vertices
MyGraph::MyGraph(int n) {
    this->n = n;
    adjList.resize(n + 1); // Resize to n+1 to include vertex labeled n
}


//Constructor to construct a new graph that is a copy of g
MyGraph::MyGraph(const MyGraph& g) {
    this->n = g.n;
    this->adjList.resize(g.adjList.size());
    for (int i = 0; i < g.adjList.size(); i++) {
        for (int j = 0; j < g.adjList[i].size(); j++) {
            this->adjList[i].push_back(g.adjList[i][j]);
        }
    }
}

// addEDGE METHOD
bool MyGraph::addEdge(int a, int b, float w) {
    // Check if vertices are within the valid range
    if (a < 1 || a > n || b < 1 || b > n) {
        cout << "Invalid vertex\n";
        return false;
    }
    // Check if edge already exists
    for (auto& edge : adjList[a - 1]) {
        if (edge.first == b) {
            cout << "Edge already exists\n";
            return false;
        }
    }
    // Add the edge to the adjacency list
    adjList[a - 1].push_back(make_pair(b, w));
    adjList[b - 1].push_back(make_pair(a, w));
    cout << "Edge added successfully\n";
    return true;
}


// OUTPUT method
void MyGraph::output(ostream& os) {
    os << n << endl;
    vector<vector<bool>> printed(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (auto& edge : adjList[i]) {
            int j = edge.first;
            float w = edge.second;
            if (i < j && !printed[i][j]) {
                os << i << " " << j << " " << w << endl;
                printed[i][j] = true;
            }
        }
    }
}


// HW2PROG method
pair<vector<int>, float> MyGraph::HW2Prog(int s, int t, bool printMST) {
    // Calculate the MST
    vector<float> key(n, -1.0);
    vector<int> parent(n, -1);
    priority_queue<pair<float, int>> pq;
    pq.push(make_pair(0.0, 0));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (key[u] != -1.0) {
            continue;
        }
        key[u] = 0;
        for (auto &edge: adjList[u]) {
            int v = edge.first;
            float w = -edge.second;
            if (key[v] == -1.0) {
                pq.push(make_pair(w, v));
                parent[v] = u;
            }
        }
    }
    // If printMST is true, print the MST to standard output
    if (printMST) {
        cout << n << endl;
        for (int i = 1; i < n; i++) {
            cout << parent[i] << " " << i << " " << -key[i] << endl;
        }
    }
    // Calculate the path with highest capacity
    vector<int> path;
    float capacity = -1.0;
    int curr = t;
    while (curr != s) {
        path.push_back(curr);
        int parent_curr = parent[curr];
        for (auto &edge: adjList[curr]) {
            if (edge.first == parent_curr) {
                capacity = max(capacity, edge.second);
                break;
            }
        }
        curr = parent_curr;
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return make_pair(path, capacity);
}