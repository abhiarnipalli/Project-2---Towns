//
// Created by Abhlash Arnipalli on 3/31/23.
//
//
// Created by Abhlash Arnipalli on 3/27/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "MyGraph.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

int main(){
    ifstream ifile("prog2input.txt");
    int n, e, c;

    ifile >> n >> e >> c;
    MyGraph g(n);

    for (int i = 0; i < e; i++){
        int s, t;
        float w;
        ifile >> s >> t >> w;
        g.AddEdge(s, t, w);
    }

    vector<int> p, q;
    for (int i = 0; i < c; i++){
        int s, t;
        ifile >> s >> t;
        p.push_back(s);
        q.push_back(t);
    }
    ifile.close();

    vector< pair<vector<int>, float> > resarray;

    // the timer will time this for loop
    auto start = high_resolution_clock::now();
    for (int i = 0; i < p.size(); i++){
        pair<vector<int>, float> res = g.HW2Prog(p[i], q[i], true);
        resarray.push_back(res);
    }
    auto stop = high_resolution_clock::now();
    auto runtime = duration_cast<microseconds>(stop - start);

    cout << "_________________________" << endl;
    for (int i = 0; i < p.size(); i++){
        cout << p[i] << " -> " << q[i] << " : Path : ";
        for (int j =0; j < resarray[i].first.size(); j++) {
            cout << resarray[i].first[j]  << "  ";
        }
        cout << "  Capacity : " << resarray[i].second << endl;
    }

    // output runtime
    cout << "_________________________" << endl;
    cout << "Runtime: " << runtime.count() << " Microseconds" << endl;

    return(0);

}
