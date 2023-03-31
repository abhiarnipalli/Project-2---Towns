#include "MyGraph.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Constructor to create a graph with n vertices
MyGraph::MyGraph(int n) {
    this->n = n;
    list.resize(n + 1);
}

// Constructor to construct a new graph that is a copy of g
MyGraph::MyGraph(const MyGraph& g) {
    n = g.n;
    list = g.list;
}

// Add an edge between vertex int a and int b, with weight float w
bool MyGraph::AddEdge(int a, int b, float w) {
    if (a < 1 || a > n || b < 1 || b > n) {
        return false;
    }
    for (auto& edge : list[a - 1]) {
        if (edge.first == b) {
            return false;
        }
    }
    list[a - 1].push_back(make_pair(b, w));
    list[b - 1].push_back(make_pair(a, w));
    return true;
}

// Output the graph
void MyGraph::output(ostream& os) {
    os << n << " " << list.size() << endl;
    for (int i = 0; i < n; i++) {
        for (auto& edge : list[i]) {
            os << i << " " << edge.first << " " << edge.second << endl;
        }
    }
}

// HW2PROG method
pair<vector<int>, float> MyGraph::HW2Prog(int s, int t, bool printMST) {
    vector<int> path;
    float max_capacity = 0.0;
    // Run Prim's algorithm
    vector<int> parent(n, -1);
    vector<float> key(n, -1.0);
    priority_queue<pair<float, int>> queue;
    queue.push(make_pair(0.0, s));
    key[s] = 1.0;
    while (!queue.empty()) {
        int u = queue.top().second;
        queue.pop();
        for (auto i = list[u].begin(); i != list[u].end(); ++i) {
            int v = i->first;
            float weight = i->second;
            if (key[v] < weight) {
                key[v] = weight;
                queue.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

//


    // find max capacity
    int v = t;
    while (v != -1) {
        path.push_back(v);
        if (v == s) {
            break;
        }
        max_capacity = max(max_capacity, key[v]);
        v = parent[v];
    }
    reverse(path.begin(), path.end());
    //if printMST is true output max spanning tree
    if (printMST) {
        MyGraph mst(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                mst.AddEdge(parent[i], i, key[i]);
            }
        }
        mst.output(cout);
    }

    return make_pair(path, max_capacity);
}