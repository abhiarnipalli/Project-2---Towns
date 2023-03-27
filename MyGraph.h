//
// Created by Abhlash Arnipalli on 3/14/23.
//
#ifndef PROGRAM2_MYGRAPH_H
#define PROGRAM2_MYGRAPH_H
#include <vector>
using namespace std;

class MyGraph {

private:
    int n;
    vector<vector<pair<int, float>>> adjList;

public:
    MyGraph(int n);
    MyGraph(const MyGraph& g);
    bool addEdge(int a, int b, float w);
    void output(ostream& os);
    // Method to find the route from s to t with highest capacity
    pair<vector<int>, float> HW2Prog(int s, int t, bool printMST);

};


#endif //PROGRAM2_MYGRAPH_H
